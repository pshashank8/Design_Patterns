#include "Publisher.h"
#include "Subscriber.h"
#include <map>

void Publisher::Register(NotificationType type, Subscriber* p) {
	m_Subscribers.insert(std::make_pair(type,p)) ;
}

void Publisher::Deregister(NotificationType type, Subscriber* p) {
	if (m_Subscribers.find(type) != m_Subscribers.end()) {
		auto range = m_Subscribers.equal_range(type);
		for (auto it = range.first; it != range.second; it++) {
			if (it->second == p) {
				m_Subscribers.erase(it);
				break;
			}
		}
	}
}

void Publisher::Notify(NotificationType type, std::any data) {
	if (m_Subscribers.find(type) != m_Subscribers.end()) {
		auto range = m_Subscribers.equal_range(type);
		for (auto it = range.first; it != range.second; it++) {
			(it->second)->Update(data);
		}
	}
}
