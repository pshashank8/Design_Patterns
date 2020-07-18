#pragma once
#include <list>
#include <any>
#include <string>
#include <unordered_map>
#include <unordered_set>

class Subscriber;

enum class NotificationType {
	Add,
	Remove
};

class Publisher
{
	std::unordered_multimap<NotificationType, Subscriber*> m_Subscribers{};
public:
	void Register(NotificationType, Subscriber* p);
	void Deregister(NotificationType, Subscriber* p);
	void Notify(NotificationType, std::any  data);
	virtual ~Publisher()=0{}
};

//class Table : Publisher {
//	std::unordered_map<std::string, int> m_Data ;
//public:
//	void Add(std::string key, int data) {
//		m_Data[key] = data ;
//		Notify(key) ;
//	}
//};