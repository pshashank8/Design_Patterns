#pragma once
#include <any>
class Subscriber
{
public:
	virtual void Update(std::any data) =0 ;
	virtual ~Subscriber() = default ;
};

