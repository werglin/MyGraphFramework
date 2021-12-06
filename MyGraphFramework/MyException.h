#pragma once

#include<exception>
#include<string>

class MyException : public std::exception
{
public:
	MyException(int line, const char* file) noexcept;
	const char* what() const noexcept override;
	virtual const char* GetType() const noexcept;
	int GetLine() const noexcept;
	const std::string& GetFile() const noexcept;
	std::string GetOriginString() const noexcept;
private:
	int line;
	std::string file;
protected:
	// We use this in what() so we need to make it mutable to use it there
	mutable std::string whatBuffer;
};

