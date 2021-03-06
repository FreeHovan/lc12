template <typename T>
class AbstractQueue
{
public:
	virtual void Push(T) = 0;
	virtual void Pop(T&) = 0;
	virtual void Peek(T&) = 0;
	virtual int GetSize() const = 0;
};