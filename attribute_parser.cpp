#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;


class Tag {
private:
	string name;
	vector<Tag*> child_tags;
	map<string, string> attributes;

public:
	Tag(string n) :name(n) {}
	Tag() {}

	void add_child(Tag* subtag) {
		child_tags.push_back(subtag);
	}

	Tag* find_tag(string tagname) {
		for (auto t: child_tags)
			if (t->name == tagname)
				return t;
		return nullptr;
	}

	string get_name(void) { return name; }

	void print(void) {
		cout << "current-tag: " << name << " : ";
		for (auto at: attributes)
			cout << "[" << at.first << "]" << "=" << "[" << at.second << "] ";
		cout << endl;
		for (auto t: child_tags)
			cout << "    child-tag: name="<< t->name << endl;
	}

	void set_name(string line)
	{
		int s, i;
		if (line[0] == '<' and line[1] != '/')
			s = i = 1;
		else
			s = i = 2;
	
		for (; i < line.size(); i++) {
			if (line[i] == ' ' || line[i] == '>') {
				break;
			}
		}
		name = line.substr(s, i-s /* lenth of sub-string */);
	}

	void set_attr(string line)
	{
		size_t len = line.size();
		if (line[len - 1] == '>' and line[len - 2] != '"')
			// no attributes
			return;

		size_t current, previous = 0;
		current = line.find(' '); // skip tag name

		// The last character should be '>'
		// -2 is for '>' and '\0'
		while (current < line.size() - 2) {
			previous = current + 1;
			current = line.find(' ', previous);
			cout << "prev=" << previous << "current=" << current << endl;
			string aname = line.substr(previous, current - previous);
			cout << "a-name: [" << aname << "]" << endl;

			previous = current + 1;
			current = line.find(' ', previous);
			cout << "prev=" << previous << "current=" << current << endl;
			string tmp = line.substr(previous, current - previous);
			cout << "equal: [" << tmp << "]" << endl;

			previous = current + 1;
			current = line.find(' ', previous);
			if (current == string::npos) {
				cout << "found last" << endl;
				current = line.find('>', previous);
			}
			cout << "prev=" << previous << "current=" << current << endl;
			string vname = line.substr(previous, current - previous);
			cout << "vname: [" << vname << "]" << endl;

			//attributes.insert(make_pair(aname, vname));
			attributes[aname] = vname;
		}
	}

};

string tag_text[] = {"<tag1 v1 = \"123\" v2 = \"43.4\" v3 = \"hello\">",
					 "</tag1>",
					 "<tag2 v4 = \"v2\" name = \"Tag2\">",
					 "<tag3 v1 = \"Hello\" v2 = \"World!\">",
					 "</tag3>",
					 "<tag4 v1 = \"Hello\" v2 = \"Universe!\">",
					 "</tag4>",
					 "</tag2>",
					 "<tag5>",
					 "<tag7 new_val = \"New\">",
					 "</tag7>",
					 "</tag5>",
					 "<tag6>",
					 "<tag8 intval = \"34\" floatval = \"9.845\">",
					 "</tag8>",
					 "</tag6>"};
int num_tag = 16;

bool isopen(string line)
{
	return line[0] == '<' and line[1] != '/';
}

void test_get_name(void)
{
	for (auto t: tag_text) {
		Tag tag;
		tag.set_name(t);
		cout << "[" << tag.get_name() << "]" << endl;
	}
}

void test_set_attr(void)
{
	string line = "<tag1 v1 = \"123\" v2 = \"43.4\" v3 = \"hello\">";
	Tag tag;
	tag.set_name(line);
	tag.set_attr(line);
	tag.print();
}

int main(void)
{
	test_get_name();
	test_set_attr();
	return 0;
}
