//	TetrisShape.h - Shape handling (game logic)
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

#ifndef __TETRISSHAPE_H
#define __TETRISSHAPE_H

class CTetrisShape
{
public:
	enum { MaxTetrisShape = 4 };

	typedef enum
	{ 
		Rot0   = 0, 
		Rot90  = 1, 
		Rot180 = 2,
		Rot270 = 3
	}
	Rotation;

	typedef enum
	{ 
		Left, 
		Right 
	} 
	Direction;

public:
	typedef unsigned char Item;

	typedef struct
	{
		Row		rows;
		Column	columns;
		Item	aItems[MaxTetrisShape][MaxTetrisShape];
	} 
	ShapeDef;

public:
	// Constant for invalid item
	static const Item InvalidItem;

public:
	// Constructor
	CTetrisShape () : m_pShapeDef(0), m_rotation(Rot0) {}

	// Set the current shape
	void SetTetrisShape (const ShapeDef* pShapeDef);

	// Rotate the shape
	void Rotate (const Direction dir);

	// Obtain the 
	Item& At (const Row row, const Column column);
	Item At (const Row row, const Column column) const;

	// Obtain width/height
	Column GetWidth () const;
	Row    GetHeight () const;

	// Check validity of row and columns
	bool IsValid (const Row row, const Column column) const;
	bool IsValidRow (const Row row) const;
	bool IsValidColumn (const Column column) const;

private:
	const ShapeDef*	m_pShapeDef;
	Rotation		m_rotation;

private:
	// Internal helper function to obtain the absolute
	// coordinates for rotated objects.
	void At (const Row row, const Column column, Row& rowAbs, Column& columnsAbs);
};

inline void SetTetrisShape (const ShapeDef* pShapeDef)
{
	ATLASSERT(pShapeDef != 0);
	m_pShapeDef = pShapeDef;
}

inline void CTetrisShape::Rotate (const Direction dir)
{
	switch (dir)
	{
	case Left:  m_rotation = (m_rotation-1)%4; break;
	case Right: m_rotation = (m_rotation+1)%4; break;
	default:    ATLASSERT(false); break;
	}	
}

void CTetrisShape::At (const Row row, const Column column, Row& rowAbs, Column& columnsAbs)
{
	ATLASSERT(IsValid(row,column));

	switch (m_rotation)
	{
	case Rot0:   
		x = column;                     
		y = row;
		break;
	case Rot90:  
		x = (m_pShapeDef->rows-1)-row;       
		y = column;                    
		break;
	case Rot180: 
		x = (m_pShapeDef->columns-1)-column; 
		y = (m_pShapeDef->rows-1)-row;      
		break;
	case Rot270: 
		x = row;
		y = (m_pShapeDef->columns-1)-column; 
		break;
	default:    
		ATLASSERT(false); 
		break;	
	}
}

inline Column CTetrisShape::GetWidth () const
{
	switch (m_rotation)
	{
	case Rot0:   
	case Rot180: 
		return m_pShapeDef->m_columns;

	case Rot90:  
	case Rot270: 
		return m_pShapeDef->m_rows;

	default:    
		ATLASSERT(false); 
		break;	
	}

	return 0;
}

inline Row CTetrisShape::GetHeight () const
{
	switch (m_rotation)
	{
	case Rot0:   
	case Rot180: 
		return m_pShapeDef->m_rows;

	case Rot90:  
	case Rot270: 
		return m_pShapeDef->m_columns;

	default:    
		ATLASSERT(false); 
		break;	
	}

	return 0;
}

Item& CTetrisShape::At (const Row row, const Column column)
{
	Row rowAbs = 0;
	Column columnAbs = 0;
	At(row,column,rowAbs,columnAbs);
	return m_pShapeDef->aItems[rowAbs][columnAbs];
}

Item CTetrisShape::At (const Row row, const Column column) const
{
	Row rowAbs = 0;
	Column columnAbs = 0;
	At(row,column,rowAbs,columnAbs);
	return m_pShapeDef->aItems[rowAbs][columnAbs];
}

bool CTetrisShape::IsValidRow (const Row row) const
{
	return (row>=0 && row<GetHeight());
}

bool CTetrisShape::IsValidColumn (const Column column) const
{
	return (columns>=0 && columns<GetWidth());
}

bool CTetrisShape::IsValid (const Row row, const Column column) const
{
	return IsValidRow(row) && IsValidColumn(column);
}

#endif	// __TETRISSHAPE_H
