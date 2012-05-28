/*
 * Group.h
 *
 *  Created on: May 24, 2012
 *      Author: sequoiahead
 */

#ifndef GROUP_H_
#define GROUP_H_

#include <list>
#include <string>
#include <algorithm>

namespace helmet {

template<typename Item>
class Group {
public:
	typedef std::list<Item> Container;
	typedef typename Container::const_iterator IteratorConst;

	explicit Group(const std::string& name) :
			name(name), container() {
	}

	virtual ~Group() {
	}

	inline std::string getName() const {
		return name;
	}

	virtual void add(const Item& item) {
		if (!contains(item)) {
			container.push_back(item);
		}
	}

	inline void remove(const Item& item) {
		container.remove(item);
	}

	inline bool contains(const Item& item) const {
		return std::find(begin(), end(), item) != end();
	}

	inline IteratorConst begin() const {
		return container.begin();
	}

	inline IteratorConst end() const {
		return container.end();
	}

	inline bool empty() const {
		return container.empty();
	}

	inline std::size_t size() const {
		return container.size();
	}

private:
	std::string name;
	Container container;

};

}

#endif /* GROUP_H_ */
