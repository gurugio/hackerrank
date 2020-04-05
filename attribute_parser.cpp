#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;


/*
 * link: https://www.hackerrank.com/challenges/attribute-parser/problem
 */


/*
Test input:
20 19
<tag1 v1 = "123" v2 = "43.4" v3 = "hello">
</tag1>
<tag2 v4 = "v2" name = "Tag2">
<tag3 v1 = "Hello" v2 = "World!">
</tag3>
<tag4 v1 = "Hello" v2 = "Universe!">
</tag4>
</tag2>
<tag5>
<tag7 new_val = "New">
</tag7>
</tag5>
<tag6>
<tag8 intval = "34" floatval = "9.845">
<ntag nv = "4$">
<nvtag nv = "6$">
</nvtag>
</ntag>
</tag8>
</tag6>
tag1~v1
tag1~v2
tag1~v3
tag4~v2
tag2.tag4~v1
tag2.tag4~v2
tag2.tag3~v2
tag5.tag7~new_val
tag5~new_val
tag7~new_val
tag6.tag8~intval
tag6.tag8~floatval
tag6.tag8~val
tag8~intval
tag6.tag8.ntag~nv
tag6.tag8.ntag.nvtag~nv
tag6.tag8.nvtag~nv
randomtag~nv
tag283.tag21.den~jef

Corrent result:
123
43.4
hello
Not Found!
Hello
Universe!
World!
New
Not Found!
Not Found!
34
9.845
Not Found!
Not Found!
4$
6$
Not Found!
Not Found!
Not Found!
*/


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
		cout << "print-tag: name=" << name << " : ";
		for (auto at: attributes)
			cout << "[" << at.first << "]" << "=" << "[" << at.second << "] ";
		cout << endl;
		for (auto t: child_tags)
			cout << "    child-tag: name="<< t->name << endl;
		for (auto t: child_tags)
			t->print();
	}

	void set_name(string& line)
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

	void set_attr(string& line)
	{
		size_t len = line.size();
		if (line[len - 1] == '>' and line[len - 2] != '"')
			// no attributes
			return;

		size_t current, previous = 0;
		size_t last = line.find('>');
		current = line.find(' '); // skip tag name

		while (current < last && current != string::npos) {
			previous = current + 1;
			current = line.find(' ', previous);
			//cout << "prev=" << previous << "current=" << current << endl;
			string aname = line.substr(previous, current - previous);
			//cout << "a-name: [" << aname << "]" << endl;

			previous = current + 1;
			current = line.find(' ', previous);
			//cout << "prev=" << previous << "current=" << current << endl;
			string tmp = line.substr(previous, current - previous);
			//cout << "equal: [" << tmp << "]" << endl;

			previous = current + 2; // skip the first '"'
			current = line.find('"', previous);
			//cout << "prev=" << previous << "current=" << current << endl;
			string vname = line.substr(previous, current - previous);
			//cout << "vname: [" << vname << "]" << endl;
		
			attributes[aname] = vname;

			current++;
			if (line[current] == '>')
				break;
		}
	}
	
	string get_attr(string attr_key)
	{
		if (attributes.find(attr_key) != attributes.end())
			return attributes[attr_key];
		else
			return "Not Found!";
	}
};

bool isopen(string& line)
{
	return line[0] == '<' and line[1] != '/';
}

void test_get_name(vector<string> tag_text)
{
	for (auto line: tag_text) {
		Tag tag;
		tag.set_name(line);
		cout << "[" << tag.get_name() << "]" << endl;
	}
}

void test_set_attr(vector<string> tag_text)
{
	for (auto line: tag_text) {
		Tag tag;
		tag.set_name(line);
		tag.set_attr(line);
		tag.print();
	}
}

int parse_tag(Tag* parent, vector<string> text, size_t maxline, size_t curline)
{
	while (curline < maxline) {
		string name;

		//cout << "parse: " << text[curline] << endl;

		if (isopen(text[curline])) {
			Tag* newtag = new Tag;
			newtag->set_name(text[curline]);
			newtag->set_attr(text[curline]);
			// cout << "Create new tag:";
			// newtag->print();
			// cout << endl;
			parent->add_child(newtag);
			curline = parse_tag(newtag, text, maxline, curline + 1);
		} else {
			//cout << "close-tag:" <<  text[curline] << endl;
			return curline + 1;
		}
	}
	return curline + 1;
}

int main(void)
{
	int num_tag, num_query;
	string tmp;
	vector<string> tags;
	vector<string> queries;

	cin >> num_tag >> num_query;
	getline(cin, tmp); // remove newline

	for (int i = 0; i < num_tag; i++) {
		getline(cin, tmp);
		tags.push_back(tmp);
	}
	for (int i = 0; i < num_query; i++) {
		getline(cin, tmp);
		queries.push_back(tmp);
	}

	// if (tags.size() == num_tag && queries.size() == num_query) {
	// 	cout << "input ok" << endl;
	// } else {
	// 	cout << "input error\n";
	// 	return 1;
	// }
	
	Tag toptag("top");

	parse_tag(&toptag, tags, num_tag, 0);

	// cout << "parse finish\n";
	// toptag.print();

	for (auto line: queries) {
		size_t current, previous = 0;
		size_t last = line.find('~');
		string tname;
		Tag *foundtag = &toptag;

		current = line.find('.', 0);
		while (current != string::npos) {
			tname = line.substr(previous, current - previous);
			previous = current + 1;
			current = line.find('.', previous);
			//cout << "1tag-name: [" << tname << "]" << endl;
			foundtag = foundtag->find_tag(tname);
			if (!foundtag) break;
		}
		if (!foundtag) {
			cout << "Not Found!\n";
			continue;
		}
		tname = line.substr(previous, last - previous);
		//cout << "2tag-name: [" << tname << "]" << endl;
		foundtag = foundtag->find_tag(tname);
		if (!foundtag) {
			cout << "Not Found!\n";
			continue;
		}

		string vname = line.substr(last + 1, line.size() - last);
		//cout << "val-name: [" << vname << "]" << endl;
		cout << foundtag->get_attr(vname) << endl;
	}

	return 0;
}
