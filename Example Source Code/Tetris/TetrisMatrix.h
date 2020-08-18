//	TetrisMatrix.h - Tetris for Pocket PC (game logic)
//  Converted To Gizmondo By TheReaper 2006
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

#ifndef __TETRIS_MATRIX_H
#define __TETRIS_MATRIX_H


class CTetrisMatrix
{
public:
 	// Constant definitions
	enum { DefRows    = 16, MinRows    = 5, MaxRows    = 16 };
	enum { DefColumns = 10, MinColumns = 5, MaxColumns = 16 };
	enum { DefSpeed   =  2, MinSpeed   = 1, MaxSpeed   =  9 };

	// Maximum size of a shape
	enum { MaxTetrisShape = 4 };

	// Rotation values
	typedef enum
	{ 
		Rot0   = 0, 
		Rot90  = 1, 
		Rot180 = 2,
		Rot270 = 3
	}
	Rotation;

	// Rotation direction
	typedef enum
	{ 
		Left,	// Left (counter clockwise)
		Right	// Right (clockwise)
	} 
	Direction;
	
	// Type definitions
	typedef int Row;
	typedef int Column;
	typedef unsigned char Speed;
	typedef unsigned char Item;

	// Constant for invalid item
	static const Item InvalidItem;

public:
	class CTetrisShape
	{
	public:
		typedef struct
		{
			Row		rows;
			Column	columns;
			Item	aItems[MaxTetrisShape][MaxTetrisShape];
		} 
		SHAPEDEF;

	public:
		// Constructors
		CTetrisShape ();
		CTetrisShape (const CTetrisShape& shape);

		// Set the shape
		void SetShape (const SHAPEDEF& shapeDef, const Rotation rotation = Rot0);

		// Rotate the shape
		void Rotate (const Direction dir);
		void Rotate (const Rotation rotation);

		// Obtain the item within the shape
		Item At (const Row row, const Column column) const;

		// Obtain width/height
		Column GetWidth () const;
		Row    GetHeight () const;

		// Check validity of row and columns
		bool IsValid (const Row row, const Column column) const;
		bool IsValidRow (const Row row) const;
		bool IsValidColumn (const Column column) const;

	private:
		const SHAPEDEF*	m_pShapeDef;
		Rotation		m_rotation;
	};

private:
	static const CTetrisShape::SHAPEDEF mg_aShapeDefinition[];

public:
	// Constructor/Destructor
	CTetrisMatrix (const Row rows, const Column columns);
	~CTetrisMatrix();

public:
	// Accessor method
	Item At (const Row row, const Column column) const;
	Item& At (const Row row, const Column column);
	Item PieceAt (const Row row, const Column column) const;

	// Information method
	Row    GetRows    () const { return m_rows;    }
	Column GetColumns () const { return m_columns; }	
	Speed  GetSpeed   () const { return m_speed;   }

	// Obtain shape information
	const CTetrisShape& GetShape () const       { return m_shape;  }
	Row                 GetShapeRow () const    { return m_row;    }
	Column              GetShapeColumn () const { return m_column; }

	// Obtain next shape information
	const CTetrisShape& GetNextShape () const { return m_shapeNext; }

	// Obtain the current score and moves
	int GetScore () const;
	bool IsGameOver () const { return m_fEndOfGame; }
	bool CanDrop () const { return m_row>0 && IsValidState(m_shape,m_row-1,m_column); }

	// User actions
	bool MoveDown (const bool fManual);
	bool MoveSideways (const Direction direction);
	bool Rotate (const Direction direction);

private:
	// Internal helper functions
	bool NewShape (void);
	bool IsValidState (const CTetrisShape& shape, const Row rowShape, const Column columnShape) const;

private:
	// Matrix validation methods
	bool IsValid (const Row row, const Column column) const;
	bool IsValidRow (const Row row) const;
	bool IsValidColumn (const Column column) const;

private:
	// Internal matrix logic
	const Row		m_rows;
	const Column	m_columns;
	Item*			m_pMatrix;
	
	// Current tetris shape
	CTetrisShape	m_shape;
	Row				m_row;
	Column			m_column;
	
	// Next tetris shape
	CTetrisShape	m_shapeNext;

	// Current speed
	bool	m_fEndOfGame;
	Speed	m_speed;

	// Current score
	int		m_iScore;

public:
	// Tetris event interface
	class CTetrisEvents
	{
	public:
		virtual void RowDeleted (const Row row) = 0;
		virtual void SpeedChange (const Speed speedNew) = 0;
		virtual void ScoreChange (const int iScore) = 0;
		virtual void NextShapeChange (const CTetrisShape& shapeNext) = 0;
	};

	// Subscribe/unsubscribe
	void Subscribe (CTetrisEvents* pEvents);
	void Unsubscribe (CTetrisEvents* pEvents);

private:
	// Internal fire functions
	void FireRowDeleted (const Row row);
	void FireSpeedChange ();
	void FireScoreChange ();
	void FireNextShapeChange ();

private:
	// Event attributes
	CTetrisEvents* m_pEvents;
};


inline CTetrisMatrix::CTetrisShape::CTetrisShape ()
	: m_pShapeDef(0)
	, m_rotation(Rot0)
{
}

inline CTetrisMatrix::CTetrisShape::CTetrisShape (const CTetrisShape& shape)
	: m_pShapeDef(shape.m_pShapeDef)
	, m_rotation(shape.m_rotation)
{
}

inline void CTetrisMatrix::CTetrisShape::SetShape (const SHAPEDEF& shapeDef, const Rotation rotation)
{
	m_pShapeDef = &shapeDef;
	m_rotation  = rotation;
}

inline void CTetrisMatrix::CTetrisShape::Rotate (const Direction dir)
{
	switch (dir)
	{
	case Left:  m_rotation = Rotation((m_rotation+3)%4); break;
	case Right: m_rotation = Rotation((m_rotation+1)%4); break;
	default:    ATLASSERT(false); break;
	}	
}

inline CTetrisMatrix::Column CTetrisMatrix::CTetrisShape::GetWidth () const
{
	switch (m_rotation)
	{
	case Rot0:   
	case Rot180: 
		return m_pShapeDef->columns;

	case Rot90:  
	case Rot270: 
		return m_pShapeDef->rows;

	default:    
		ATLASSERT(false); 
		break;	
	}

	return 0;
}

inline CTetrisMatrix::Row CTetrisMatrix::CTetrisShape::GetHeight () const
{
	switch (m_rotation)
	{
	case Rot0:   
	case Rot180: 
		return m_pShapeDef->rows;

	case Rot90:  
	case Rot270: 
		return m_pShapeDef->columns;

	default:    
		ATLASSERT(false); 
		break;	
	}

	return 0;
}

inline CTetrisMatrix::Item CTetrisMatrix::CTetrisShape::At (const Row row, const Column column) const
{
	ATLASSERT(IsValid(row,column));

	Row rowAbs = 0;
	Column columnAbs = 0;
	switch (m_rotation)
	{
	case Rot0:   return m_pShapeDef->aItems[row][column];
	case Rot90:  return m_pShapeDef->aItems[(m_pShapeDef->rows-1)-column][row];
	case Rot180: return m_pShapeDef->aItems[(m_pShapeDef->rows-1)-row][(m_pShapeDef->columns-1)-column];
	case Rot270: return m_pShapeDef->aItems[column][(m_pShapeDef->columns-1)-row];
	}

	ATLASSERT(false);
	return InvalidItem;
}

inline bool CTetrisMatrix::CTetrisShape::IsValidRow (const Row row) const
{
	return (row>=0 && row<GetHeight());
}

inline bool CTetrisMatrix::CTetrisShape::IsValidColumn (const Column column) const
{
	return (column>=0 && column<GetWidth());
}

inline bool CTetrisMatrix::CTetrisShape::IsValid (const Row row, const Column column) const
{
	return IsValidRow(row) && IsValidColumn(column);
}



inline int CTetrisMatrix::GetScore() const
{
	// Return the current score
	return m_iScore;
}

inline bool CTetrisMatrix::IsValidRow (const Row row) const
{
	return (row>=0) && (row<m_rows);
}

inline bool CTetrisMatrix::IsValidColumn (const Column column) const
{
	return (column>=0) && (column<m_columns);
}

inline bool CTetrisMatrix::IsValid (const Row row, const Column column) const
{
	return IsValidRow(row) && IsValidColumn(column);
}

inline CTetrisMatrix::Item CTetrisMatrix::At (const Row row, const Column column) const
{
	ATLASSERT(IsValid(row,column));

	// Obtain the item in the matrix
	return m_pMatrix[row*m_columns+column];
}

inline CTetrisMatrix::Item& CTetrisMatrix::At (const Row row, const Column column)
{
	ATLASSERT(IsValid(row,column));

	// Obtain the item in the matrix
	return m_pMatrix[row*m_columns+column];
}

inline CTetrisMatrix::Item CTetrisMatrix::PieceAt (const Row row, const Column column) const
{
	ATLASSERT(IsValid(row,column));

	// Check if the item is within the shape
	if ((row<m_row) || 
		(row>=m_row+m_shape.GetHeight() ||
		(column<m_column) || 
		(column>=m_column+m_shape.GetWidth())))
	{
		return InvalidItem;
	}

	// Obtain the item from the shape
	return m_shape.At(row-m_row,column-m_column);
}

inline void CTetrisMatrix::Subscribe (CTetrisEvents* pEvents)
{
	ATLASSERT(pEvents != 0);
	ATLASSERT(m_pEvents == 0);

	m_pEvents = pEvents;
}

inline void CTetrisMatrix::Unsubscribe (CTetrisEvents* pEvents)
{
	ATLASSERT(pEvents != 0);
	ATLASSERT(m_pEvents == pEvents);

	m_pEvents = 0;
}

inline void CTetrisMatrix::FireRowDeleted (const Row row)
{
	ATLASSERT(IsValidRow(row));

	if (m_pEvents)
		m_pEvents->RowDeleted (row);
}

inline void CTetrisMatrix::FireSpeedChange ()
{
	if (m_pEvents)
		m_pEvents->SpeedChange(GetSpeed());
}

inline void CTetrisMatrix::FireScoreChange ()
{
	if (m_pEvents)
		m_pEvents->ScoreChange(GetScore());
}

inline void CTetrisMatrix::FireNextShapeChange ()
{
	if (m_pEvents)
		m_pEvents->NextShapeChange(GetNextShape());
}



#endif // __TETRIS_MATRIX_H
