#include < stdio.h >

template < typename T >

class Conteiner 
{
private:
	struct Element
	{
		T m_value;
		Element * m_next;
		Element * m_previous;
		int tag;
	};
	Element * m_head;
	Element * m_tail;
	int m_quanity;
public:
	Conteiner( )
	{
		m_head = NULL;
		m_tail = NULL;
		m_quanity = 0;
	};
	~Conteiner( )
	{
		Element * current = m_head;
		Element * current2 = m_head;
		while ( current != NULL )
		{
			current2 = (current -> m_previous);
			delete current;
			current = current2;
		}
	};
	Conteiner( const Conteiner & orig )
	{
		this -> m_head = orig.m_head;
		this -> m_tail = orig.m_tail;
	}
	 void DelTail() // удаление последнего
	 {
		 if (m_tail != NULL)
		 {
			 Element* current = m_tail->m_next;
			 delete m_tail;
			 m_tail = current;
			 m_quanity --;
		 }
	 }
	 void DelHead( ) // delete first element
	 {
		 if (m_head != NULL)
		 {
			 Element * current = m_head -> m_previous;
			 delete m_head;
			 m_head = current;
			 m_quanity --;
		 }
	 }
	 T GetHead( ) // get value of first element
	 {
		 if (m_head != NULL)
		 {
			 return m_head -> m_value;
		 } 

	 }
	 T GetTail( ) // get value of last element
	 {
		 if (m_tail != NULL)
		 {
			 return m_tail -> m_value;
		 } 
	 }
	 T GetElement(int numb) // get element with number "numb" 
	 {
		 int i = 0;
		 Element* current = m_tail;
		 while (( current != NULL ) || ( i = numb ))
		 {
			 current = current -> m_next;
			 i ++;
		 } 
		 return current;
	 }
	 void PutHead(T newval) // add first element
	 {
		 Element * newhead = new Element;
		 newhead -> m_next = NULL;
		 newhead -> m_previous = m_head;
		 newhead -> m_value = newval;
		 m_head = newhead;
		 if ( m_tail == NULL ) m_tail = m_head;
		 m_quanity ++;
	 }
	 void PutTail( T newval ) // Add last element
	 {
		 Element * newtail = new Element;
		 newtail -> m_next = m_tail;
		 newtail -> m_previous = NULL;
		 newtail -> m_value = newval;
		 m_tail = newtail;
		  if ( m_head == NULL ) m_head = m_tail;
		 m_quanity ++;
	 }
	 bool IsEmpty( ) //checking of empty
	 {
		 return ( m_head == NULL ); 
	 }
	 void Clearn( )
	 {
		Element * current = m_head;
		Element * current2 = m_head;
		while ( current != NULL )
		{
			current2 = ( current -> m_previous );
			delete current;
			current = current2;
		}
		m_head = NULL;
		m_tail = NULL;
		m_quanity = 0;
	 }
	 int GetQuanity( ) // get count of elements
	 {
		 return m_quanity;
	 }
};
