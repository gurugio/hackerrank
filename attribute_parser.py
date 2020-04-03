import re


class Tag:
    def __init__(self, name = ""):
        self.name = name
        self.child_tags = []
        self.attributes = {}

    def set_name(self, name):
        self.name = name
        
    def add_child(self, subtag):
        self.child_tags.append(subtag)

    def print(self):
        if len(self.child_tags) != 0:
            print("parent: {}".format(self.name))
            for t in self.child_tags:
                print("   child: {} {}".format(t.name, t.attributes))
            for t in self.child_tags:
                t.print()

    def find_tag(self, tagname):
        for t in self.child_tags:
            if t.name == tagname:
                return t
        return None
                
# num_query = 14
tag_text = """<tag1 v1 = "123" v2 = "43.4" v3 = "hello">
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
</tag8>
</tag6>
"""
num_tag = len(tag_text.splitlines())

def get_name(line):
    if line[0] == '<' and line[1] == '/':
        return line.split()[0][2:-1]

    # <tagname var = "asdf"> or <tagname>
    if line[-1] == '>' and line[-2] == '"':
        return line.split()[0][1:]
    if line[-1] == '>' and line[-2] != '"':
        return line.split()[0][1:-1]

def is_open(line):
    if line[0] == '<' and line[1] == '/':
        return False
    else:
        return True

def get_attr(line):
    if line[-1] == '>' and line[-2] != '"':
        # <tagname> -> no attributes
        return None

    # there are attributes
    index = 0
    tokens = line.split()[1:]
    attr_dict = {}
    while index < len(tokens):
        name = tokens[index]
        val = tokens[index + 2]
        if val[-1] == '>': # last value
            val = val[:-1]
        attr_dict[name] = val
        index = index + 3
    
    print("attr dict: ", attr_dict)
    return attr_dict
    
def parse_text(parent_tag, start_line):
    while start_line < num_tag:
        cur_line = tag_text.splitlines()[start_line]
        print("cur-line[{}]:".format(start_line, cur_line))
        if is_open(cur_line):
            name = get_name(cur_line)
            print("open-tag name: [{}]".format(name))
            tag = Tag(name)
            tag.attributes = get_attr(cur_line)
            # parent_Tag.add_chile(new_tag)
            print("add-tag: parent={} child={}".format(parent_tag.name, tag.name))
            parent_tag.add_child(tag)
            start_line = parse_text(tag, start_line + 1)
        else:
            print("close-tag: ", get_name(cur_line))
            return start_line + 1

    return start_line


query_text = """tag1~v1
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
"""

top_tag = Tag("top")
parse_text(top_tag, 0)
top_tag.print()

for query in query_text.splitlines():
    print("query:", query)
    tag_list = re.split('\.|~', query)
    print("tag-list:", tag_list)
    cur_tag = top_tag
    for name in tag_list[:-1]:
        cur_tag = cur_tag.find_tag(name)
        if cur_tag is None:
            print("No such tag: ", name)
            break
        else:
            print("cur_tag:", cur_tag.name)

    if cur_tag is None:
        continue
    
    if cur_tag.attributes is not None and tag_list[-1] in cur_tag.attributes:
        print(cur_tag.attributes[tag_list[-1]])
    else:
        print("No such attribute: ", tag_list[-1])

