static const auto fast = []()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}
();
class iNode
{
protected:
    vector<string> split(string &path)
    {
        vector<string> ret;
        int start = 0;

        if (path[0] == '/') {
            start = 1;
        }

        int i = 1;

        while (i < path.size()) {
            for (; i < path.size() && path[i] != '/'; ++i);

            ret.emplace_back(path.substr(start, i - start));
            start = ++i;
        }

        return ret;
    }
public:
    iNode() {}
    virtual ~iNode() {}
};
class File : public iNode
{
    string data;
public:
    void addContentToFile(string &str)
    {
        data += str;
    }
    string readContentFromFile()
    {
        return data;
    }
};
class Dir : public iNode
{
    map<string, iNode *> sub_nodes;
public:
    void mkdir(string &path)
    {
        vector<string> dic = split(path);
        Dir *root = this;

        for (auto &i : dic) {
            if (root->sub_nodes.find(i) == root->sub_nodes.end()) {
                root->sub_nodes.emplace(i, new Dir);
            }

            root = dynamic_cast<Dir *>(root->sub_nodes[i]);
        }
    }
    File *mkfile(string &path)
    {
        vector<string> dic = split(path);
        Dir *root = this;

        for (size_t i = 0; i < dic.size() - 1; ++i) {
            if (root->sub_nodes.find(dic[i]) == root->sub_nodes.end()) {
                root->sub_nodes.emplace(dic[i], new Dir);
            }

            root = dynamic_cast<Dir *>(root->sub_nodes[dic[i]]);
        }

        if (root->sub_nodes.find(dic[dic.size() - 1]) == root->sub_nodes.end()) {
            root->sub_nodes.emplace(dic[dic.size() - 1], new File);
        }

        return dynamic_cast<File *>(root->sub_nodes[dic[dic.size() - 1]]);
    }
    vector<string> ls(string &path)
    {
        vector<string> ret;
        vector<string> dic = split(path);
        Dir *root = this;

        for (auto &i : dic) {
            if (root->sub_nodes.find(i) == root->sub_nodes.end()) {
                return ret;;
            }

            root = dynamic_cast<Dir *>(root->sub_nodes[i]);
        }

        if (NULL == root) {
            ret.emplace_back(dic.back());
        } else {
            for (auto &i : root->sub_nodes) {
                ret.emplace_back(i.first);
            }
        }

        return ret;
    }
};
class FileSystem
{
    Dir root;
public:
    FileSystem() {}
    vector<string> ls(string path)
    {
        return root.ls(path);
    }
    void mkdir(string path)
    {
        root.mkdir(path);
    }
    void addContentToFile(string filePath, string content)
    {
        root.mkfile(filePath)->addContentToFile(content);
    }
    string readContentFromFile(string filePath)
    {
        return root.mkfile(filePath)->readContentFromFile();
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */