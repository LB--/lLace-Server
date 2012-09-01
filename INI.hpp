#ifndef INI_HeaderPlusPlus
#define INI_HeaderPlusPlus
#include <string>
#include <sstream>
#include <map>
#include <limits>
#ifdef max //Windows.h evilness
#undef max
#endif

class INI
{
	std::map<std::string, std::map<std::string, std::string> > data;

	static void strip_r(std::string &str)
	{
		for(std::string::iterator it = str.begin(); it != str.end();)
		{
			if(*it == '\r')
			{
				it = str.erase(it);
			}
			else
			{
				++it;
			}
		}
	}
	void read(std::string from, bool merge = false)
	{
		strip_r(from);
		from.insert(from.begin(), '\n');
		if(!merge){ data.clear(); }
		std::istringstream ss (from, std::istringstream::in|std::istringstream::binary);
		if(ss.good())
		{
			int ch, next;
			std::string group, item, value;
			bool IV = false;
			while((ch = ss.get()) != EOF)
			{
				next = ss.peek();
				if(char(ch) == '\n')
				{
					if(IV)
					{
						data[group][item] = value;
					}
					item = value = "";
					IV = false;
				}
				else if(char(ch) == '=')
				{
					IV = true;
				}
				else
				{
					(IV ? value : item) += char(ch);
				}

				if(char(ch) == '\n' && next != EOF)
				{
					if(char(next) == ';')
					{
						ss.ignore();
						ss.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					}
					else if(char(next) == '[')
					{
						group = "";
						ss.ignore();
						while((ch = ss.get()) != EOF && char(ch) != ']')
						{
							group += char(ch);
						}
					}
				}
			}
			//
		}
	}
public:
	INI(){}
	INI(const std::string &from)
	{
		read(from);
	}
	INI(const INI &from) : data(from.data) {}

	INI& operator=(const std::string &from)
	{
		read(from);
		return(*this);
	}
	INI& operator=(const INI &from)
	{
		data = from.data;
		return(*this);
	}
	INI& operator+=(const std::string &with)
	{
		read(with, true);
		return(*this);
	}
	INI& operator+=(const INI &with)
	{
		for(std::map<std::string, std::map<std::string, std::string> >::const_iterator it = with.data.begin(); it != with.data.end(); ++it)
		{
			for(std::map<std::string, std::string>::const_iterator jt = it->second.begin(); jt != it->second.end(); ++jt)
			{
				data[it->first][jt->first] = jt->second;
			}
		}
		return(*this);
	}

	bool GroupExists(const std::string &group) const
	{
		return(data.find(group) != data.end());
	}
	bool ItemExists(const std::string &group, const std::string &item) const
	{
		return(data.find(group) != data.end() && data.find(group)->second.find(item) != data.find(group)->second.end());
	}

	std::string& operator()(const std::string &group, const std::string &item)
	{
		return(data[group][item]);
	}
	const std::string& operator()(const std::string &group, const std::string &item) const
	{
		const static std::string s;
		if(!ItemExists(group, item))
		{
			return(s);
		}
		return(data.find(group)->second.find(item)->second);
	}

	operator std::string() const
	{
		std::string ret;
		for(std::map<std::string, std::map<std::string, std::string> >::const_iterator it = data.begin(); it != data.end(); ++it)
		{
			ret = ret + '[' + it->first + "]\n";
			for(std::map<std::string, std::string>::const_iterator jt = it->second.begin(); jt != it->second.end(); ++jt)
			{
				ret += jt->first + '=' + jt->second + '\n';
			}
			ret += '\n';
		}
		return(ret);
	}

	~INI(){}
};

#endif
