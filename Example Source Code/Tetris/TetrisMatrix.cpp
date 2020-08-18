//	TetrisMatrix.cpp - Tetris for Pocket PC (game logic)
//
//	Copyright (C) 2000-2004 Ramon de Klein (Ramon.de.Klein@ict.nl)
//
//	This program is free software; you can redistribute it and/or modify
//	it under the terms of the GNU General Public License as published by
//	the Free Software Foundation; either version 2 of the License, or
//	(at your option) any later version.
//
//	This program is distributed in the hope that it will be useful,
//	but WITHOUT ANY WARRANTY; without even the implied warranty of
//	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//	GNU General Public License for more details.
//
//	You should have received a copy of the GNU General Public License
//	along with this program; if not, write to the Free Software
//	Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

#include "StdAfx.h"
#include "TetrisMatrix.h"


const CTetrisMatrix::Item CTetrisMatrix::InvalidItem = CTetrisMatrix::Item(0);

const CTetrisMatrix::CTetrisShape::SHAPEDEF CTetrisMatrix::mg_aShapeDefinition[] =
{
	// Blue - The J tetramino
	{
		2,	// 2 rows
		3,	// 3 columns
		{
			{ 4, 4, 4 },
			{ 0, 0, 4 }
		}
	},

	// Magenta - The L tetramino
	{
		2,	// 2 rows
		3,	// 3 columns
		{
			{ 5, 5, 5 },
			{ 5, 0, 0 }
		}
	},

	// Green - The S tetramino
	{
		2,	// 2 rows
		3,	// 3 columns
		{
			{ 0, 2, 2 },
			{ 2, 2, 0 }
		}
	},

	// Gray - The box tetramino
	{
		2,	// 2 rows
		2,	// 2 columns
		{
			{ 7, 7 },
			{ 7, 7 }
		}
	},

	// Red - The Z tetramino
	{
		2,	// 2 rows
		3,	// 3 columns
		{
			{ 6, 6, 0 },
			{ 0, 6, 6 }
		}
	},

	// Yellow - The T tetramino
	{
		2,	// 2 rows
		3,	// 3 columns
		{
			{ 1, 1, 1 },
			{ 0, 1, 0 }
		}
	},

	// Light Blue - The I tetramino
	{
		1,	// 1 row
		4,	// 4 columns
		{
			{ 3, 3, 3, 3 }
		}
	}
};



CTetrisMatrix::CTetrisMatrix (const Row rows, const Column columns)
	: m_rows(rows)
	, m_columns(columns)
	, m_speed(1)
	, m_fEndOfGame(false)
	, m_pEvents(0)
	, m_iScore(0)
{
	// Make sure all values are within range
	ATLASSERT(rows    >= MinRows    && rows    <= MaxRows   );
	ATLASSERT(columns >= MinColumns && columns <= MaxColumns);

	// Allocate memory for the bubblet matrix
	m_pMatrix = new Item[m_rows*m_columns];
	ATLASSERT(m_pMatrix);

	// Clear the matrix
	memset(m_pMatrix,InvalidItem,m_rows*m_columns*sizeof(Item));

	// Initialize random seed
	srand(::GetTickCount());

	// Determine the new shape
	const int iShapes = sizeof(mg_aShapeDefinition)/sizeof(*mg_aShapeDefinition);
	m_shapeNext.SetShape(mg_aShapeDefinition[rand()%iShapes],Rotation(rand()%4));

	// Start with a new shape
	NewShape();
}

CTetrisMatrix::~CTetrisMatrix()
{
	// Free the allocated memory
	delete[] m_pMatrix;
}

bool CTetrisMatrix::NewShape (void)
{
	// Use the next shape
	m_shape = m_shapeNext;

	// Set the starting row/column
	m_row    = m_rows-m_shape.GetHeight();
	m_column = m_columns/2;

	// Check if the shape is valid
	if (!IsValidState(m_shape,m_row,m_column))
	{
		m_fEndOfGame = true;
		return false;
	}

	// Determine the new shape
	const int iShapes = sizeof(mg_aShapeDefinition)/sizeof(*mg_aShapeDefinition);
	m_shapeNext.SetShape(mg_aShapeDefinition[rand()%iShapes],Rotation(rand()%4));

	// Fire event that the next shape has changed
	FireNextShapeChange();

	// New shape created successfully
	return true;
}

bool CTetrisMatrix::MoveSideways (const Direction direction)
{
	switch (direction)
	{
	case Left:
		if (IsValidState(m_shape,m_row,m_column-1))
		{
			--m_column;
			return true;
		}
		break;

	case Right:
		if (IsValidState(m_shape,m_row,m_column+1))
		{
			++m_column;
			return true;
		}
		break;
	}

	return false;
}

bool CTetrisMatrix::MoveDown (const bool fManual)
{
	// Check if the shape is fixed on the bottom right now
	if (!CanDrop())
	{
		Row row;
		Column column;

		// Copy the shape into the matrix
		for (row=0; row<m_rows; ++row)
		{
			for (column=0; column<m_columns; ++column)
			{
				const Item item = PieceAt(row,column);
				if (item != InvalidItem)
					At(row,column) = item;
			}
		}

		// Delete full rows
		int iFullRows = 0;
		row=0;
		while (row<m_rows)
		{
			bool fRowFull = true;
			for (column=0; fRowFull && (column<m_columns); ++column)
			{
				const Item item = At(row,column);
				if (item == InvalidItem)
					fRowFull = false;
			}

			// If the row is full then we need to clear the row
			if (fRowFull)
			{
				// Fire event that the row has been deleted
				FireRowDeleted(row);

				// Move the entire matrix down
				for (Row rowCopy=row+1; rowCopy<m_rows; ++rowCopy)
				{
					for (Column columnCopy=0; columnCopy<m_columns; ++columnCopy)
					{
						At(rowCopy-1,columnCopy) = At(rowCopy,columnCopy);
					}
				}

				// Clear the top row
				for (Column columnClear=0; columnClear<m_columns; ++columnClear)
				{
					At(m_rows-1,columnClear) = InvalidItem;
				}

				// Update the number of full rows
				++iFullRows;
			}
			else
			{
				// Check next row
				++row;
			}
		}

		// Update the score
		if (iFullRows>0)
		{
			// Remember the old score
			const int iScoreOld = m_iScore;

			// Update score
			switch (iFullRows)
			{
			case 1: m_iScore +=  100; break;
			case 2: m_iScore +=  400; break;
			case 3: m_iScore +=  900; break;
			case 4: m_iScore += 2000; break;
			default: ATLASSERT(0); break;
			}
			FireScoreChange();

			// Check if we need to increase the speed
			if (iScoreOld/2000 != m_iScore/2000)
			{
				// Increase speed (only until level 10)
				if (m_speed < MaxSpeed)
				{
					++m_speed;
					FireSpeedChange();
				}
			}
		}

		// Display a new shape
		NewShape();
		return false;
	}

	// Move the item down (manual drops increase score)
	if (fManual)
	{
		++m_iScore;
		FireScoreChange();
	}

	// Drop the shape
	--m_row;
	return true;
}

bool CTetrisMatrix::Rotate (const Direction direction)
{
	CTetrisShape shape(m_shape);
	shape.Rotate(direction);
	if (IsValidState(shape,m_row,m_column))
	{
		m_shape.Rotate(direction);
		return true;
	}

	return false;
}

bool CTetrisMatrix::IsValidState (const CTetrisShape& shape, const Row rowShape, const Column columnShape) const
{
	// Check if the shape fits in the matrix
	if (!IsValidColumn(columnShape)) return false;
	if (!IsValidColumn(columnShape+shape.GetWidth()-1)) return false;

	// Check if there is no overlap
	for (Row row=0; row<m_rows; ++row)
	{
		for (Column column=0; column<m_columns; ++column)
		{
			if (m_pMatrix[row*m_columns+column] != InvalidItem)
			{
				// Check if the item is within the shape
				if ((row<rowShape) || 
					(row>=rowShape+shape.GetHeight() ||
					(column<columnShape) || 
					(column>=columnShape+shape.GetWidth())))
				{
					continue;
				}

				// Obtain the item from the shape
				if (shape.At(row-rowShape,column-columnShape) != InvalidItem)
					return false;
			}
		}
	}

	return true;
}
