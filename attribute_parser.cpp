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
		cout << "current-tag: " << name << endl;
		for (auto t: child_tags)
			cout << "    child-tag: name="<< t->name << endl;
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


string get_name(string line)
{
	int s, i;
	if (line[0] == '<' and line[1] == '/')
		s = i = 2;
	else
		s = i = 1;
	
	for (; i < line.size(); i++) {
		if (line[i] == ' ' || line[i] == '>') {
			break;
		}
	}
	return line.substr(s, i-s /* lenth of sub-string */);
}

int main(void)
{
	for (auto t: tag_text)
		cout << "[" << get_name(t) << "]" << endl;
	
	return 0;
}
