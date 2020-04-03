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

    def add_attr(self, name, value):
        self.attributes[name] = value

    def print(self):
        if len(self.child_tags) != 0:
            print("parent: {}".format(self.name))
            for t in self.child_tags:
                print("   child: {}".format(t.name))
            for t in self.child_tags:
                t.print()

# num_tag = 16
# num_query = 14
# tag_text = """<tag1 v1 = "123" v2 = "43.4" v3 = "hello">
# <tag2 v4 = "v2" name = "Tag2">
# <tag3 v1 = "Hello" v2 = "World!">
# </tag3>
# <tag4 v1 = "Hello" v2 = "Universe!">
# </tag4>
# </tag2>
# <tag5>
# <tag7 new_val = "New">
# </tag7>
# </tag5>
# <tag6>
# <tag8 intval = "34" floatval = "9.845">
# </tag8>
# </tag6>
# """
tag_text = """<tag1>
<tag2>
<tag3>
</tag3>
<tag4>
</tag4>
</tag2>
<tag5>
</tag5>
</tag1>
<tag6>
<tag7>
</tag7>
</tag6>""".splitlines()
num_tag = len(tag_text)

def get_name(line):
    if line[0] == '<' and line[1] == '/':
        return line[2:-1]
    else:
        return line[1:-1]

def is_open(line):
    if line[0] == '<' and line[1] == '/':
        return False
    else:
        return True
    
def parse_text(parent_tag, start_line):
    while start_line < num_tag:
        cur_line = tag_text[start_line]
        print("cur-line:", cur_line)
        if is_open(cur_line):
            name = get_name(cur_line)
            print("open-tag name: [{}]".format(name))
            tag = Tag(name)
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
