#ifndef __SHAPE_H
#define __SHAPE_H

class CShape
{
public:
	typedef struct tagShape
	{
		Row		rows;
		Column	columns;
		Item	aItems[MaxShape][MaxShape];
	} 
	Shape;

public:
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
	// Constructor
	CShape () : m_shape(0), m_rotation(Rot0) {}

	// Set the current shape
	void SetShape (const Shape* pShape);

	// Rotate the shape
	void Rotate (const Direction dir);

	// Obtain the 
	Item& At (const Row row, const Column column);
	Item At (const Row row, const Column column) const;

	// Obtain width/height
	Column GetWidth () const;
	Row    GetHeight () const;

	// Check validity of row and columns
	bool IsValid (const Row row, const Column column)
	bool IsValidRow (const Row row)
	bool IsValidColumn (const Column column)

private:
	const Shape*	m_pShape;
	Rotation		m_rotation;

private:
	// Internal helper function to obtain the absolute
	// coordinates for rotated objects.
	void At (const Row row, const Column column, Row& rowAbs, Column& columnsAbs);

};

inline void CShape::Rotate (const Direction dir)
{
	switch (dir)
	{
	case Left:  m_rotation = (m_rotation-1)%4; break;
	case Right: m_rotation = (m_rotation+1)%4; break;
	default:    ATLASSERT(false); break;
	}	
}

void CShape::At (const Row row, const Column column, Row& rowAbs, Column& columnsAbs)
{
	ATLASSERT(IsValid(row,column));

	switch (m_rotation)
	{
	case Rot0:   
		x = column;                     
		y = row;
		break;
	case Rot90:  
		x = (m_shape.rows-1)-row;       
		y = column;                    
		break;
	case Rot180: 
		x = (m_shape.columns-1)-column; 
		y = (m_shape.rows-1)-row;      
		break;
	case Rot270: 
		x = row;
		y = (m_shape.columns-1)-column; 
		break;
	default:    
		ATLASSERT(false); 
		break;	
	}
}

inline Column CShape::GetWidth () const
{
	switch (m_rotation)
	{
	case Rot0:   
	case Rot180: 
		return m_pShape->m_columns;

	case Rot90:  
	case Rot270: 
		return m_pShape->m_rows;

	default:    
		ATLASSERT(false); 
		break;	
	}

	return 0;
}

inline Row CShape::GetHeight () const
{
	switch (m_rotation)
	{
	case Rot0:   
	case Rot180: 
		return m_pShape->m_rows;

	case Rot90:  
	case Rot270: 
		return m_pShape->m_columns;

	default:    
		ATLASSERT(false); 
		break;	
	}

	return 0;
}

Item& CShape::At (const Row row, const Column column)
{
	Row rowAbs = 0;
	Column columnAbs = 0;
	At(row,column,rowAbs,columnAbs);
	return m_pShape->aItems[rowAbs][columnAbs];
}

Item CShape::At (const Row row, const Column column) const
{
	Row rowAbs = 0;
	Column columnAbs = 0;
	At(row,column,rowAbs,columnAbs);
	return m_pShape->aItems[rowAbs][columnAbs];
}

bool CShape::IsValidRow (const Row row)
{
	return (row>=0 && row<GetHeight());
}

bool CShape::IsValidColumn (const Column column)
{
	return (columns>=0 && columns<GetWidth());
}

bool CShape::IsValid (const Row row, const Column column)
{
	return IsValidRow(row) && IsValidColumn(column);
}

#endif	// __SHAPE_H
