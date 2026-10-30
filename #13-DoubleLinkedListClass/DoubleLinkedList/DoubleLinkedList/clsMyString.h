#pragma once
#include <stack>
using namespace std;

class clsMyString
{
private:
	stack <string> _Undo;
	stack <string> _Redo;
	string _Value;

public:
	
	void SetValue(string v)
	{
		_Undo.push(_Value);
		_Value = v;
	}

	string GetValue()
	{
		return _Value;
	}

	__declspec(property(get = GetValue, put = SetValue))string Value;

	void Undo()
	{
		if (!_Undo.empty())
		{
			_Redo.push(_Value);
			_Value = _Undo.top();
			_Undo.pop();
		}
	}

	void Redo()
	{
		if (!_Redo.empty())
		{
			_Undo.push(_Value);
			_Value = _Redo.top();
			_Redo.pop();
		}
	}
};

