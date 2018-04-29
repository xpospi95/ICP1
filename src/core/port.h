#ifndef PORT_H
#define PORT_H

#include <string>
#include "type.h"

class BlockBase;

class Port
{
private:
	std::string name;
	Type data;
public:
	const BlockBase &block;
	Port(const BlockBase & b, const Type &t, std::string name);
	virtual bool HasValue() const = 0;
	virtual Type & Value() = 0;
	operator Type &();
	TypeValue & operator[](const std::string &s);
};

class InPort : public Port
{
public:
	InPort(const BlockBase & b, const Type &t, std::string name);
	bool HasValue() const override;
	Type & Value() override;
};

class OutPort : public Port
{
public:
	OutPort(const BlockBase & b, const Type &t, std::string name);
	bool HasValue() const override;
	Type & Value() override;
};


#endif // PORT_H
