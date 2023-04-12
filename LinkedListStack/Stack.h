#pragma once

class Stack
{

private:
	class Link
	{
	public:
		Link(Link* pPrev, int data)
			:
			data(data),
			pPrev(pPrev)
		{}
		int GetData()
		{
			return data;
		}
		Link* GetPrev()
		{
			return pPrev;
		}

	private:
		int data;
		Link* pPrev = nullptr;
			

	};


public:
	Stack() = default; //Default constructor 
	
	
	Stack(const Stack& source) //copy constructor
	{
		*this = source;
	}

	Stack& operator=(const Stack& source) // Copy assign
	{
		
		for (; pLast != nullptr;) Pop();

		if (!source.Empty())
		{
			int sourceSize = source.Size();
			int* pData = new int[sourceSize]; //creo un array auxiliar dinamico seugn el tamaño del stack para almacenar los datos

			Link* pLink = source.pLast; //Obtengo el ultimo elemento del stack pasado como parametro
			for (int i = sourceSize - 1; pLink != nullptr && i >= 0; pLink = pLink->GetPrev(), i--)
			{
				pData[i] = pLink->GetData(); // Hago una copia de todos los datos de los links
			}

			// Una vez lleno el array con la data, lo cargo en el nuevo stack
			for (int i = 0; i < sourceSize; i++)
			{
				Push(pData[0]);
			}

			delete[] pData; //Borro el array auxiliar
		}

		
		return *this;
	}

	~Stack() //Destructor
	{
		for (; pLast != nullptr;) Pop();
	}

	void Push( int val )
	{
		pLast = new Link(pLast, val);
		size++;
	}
	int Pop()
	{
		if (size >= 1)
		{
			int data = pLast->GetData();
			Link* pPrevious = pLast->GetPrev();
			delete pLast;
			pLast = nullptr;
			pLast = pPrevious;
			size--;
			return data;
		}
		else
		{
			return -1;
		}
	
	}

	int Size() const
	{
		return size;
	}
	bool Empty() const
	{
		return (size == 0);
	}
private:
	int size = 0;
	Link* pLast = nullptr;
};