#ifndef MESSAGE_FOLDER_H_
#define MESSAGE_FOLDER_H_

#include <iostream>
#include <set>
#include <string>
#include <utility>

class Folder;

class Message {
    friend class Folder;
    friend void swap(Message &, Message &);

   private:
    std::string contents;        //实际包含的消息文本
    std::set<Folder *> folders;  //包含本 Message 的 Folder
    //拷贝构造函数、拷贝赋值运算符和析构函数所使用的工具函数
    void add_to_Folders(const Message &);
    //从 folders 中的每个 Folder 中删除本 Message
    void remove_from_Folders();

   public:
    //folders 被隐式初始化为空的 set
    explicit Message(const std::string &str = "") : contents(str) {}
    //拷贝控制成员，用来管理指向本 Message 的指针
    Message(const Message &);             //拷贝构造函数
    Message &operator=(const Message &);  //拷贝赋值运算符
    ~Message();
    //从给定 Folder 中添加/删除本 Message
    void save(Folder &);
    void remove(Folder &);

    void addFolder(Folder *f) { folders.insert(f); }
    void remFolder(Folder *f) { folders.erase(f); }

    void print();
};

class Folder {
    friend class Message;
    friend void swap(Folder &, Folder &);

   private:
    std::set<Message *> messages;
    void add_to_message(Message &m) {
        if (m.folders.find(this) == m.folders.end())
            m.folders.insert(this);
    }
    void remove_from_message(Message &m) {
        if (m.folders.find(this) != m.folders.end())
            m.folders.erase(this);
    }

    void add_to_messages() {
        for (auto m : messages)
            m->folders.insert(this);
    }
    void remove_from_messages() {
        for (auto m : messages)
            m->folders.erase(this);
    }

   public:
    //默认构造函数，将 messages 初始化为空的 set
    Folder() = default;
    //拷贝一个 Folder 要更新每一个新的 Message 中的 Folder
    Folder(const Folder &);
    //赋值一个 Folder，要拷贝所有的 Message，同时更新其中的 Folder
    Folder &operator=(const Folder &);
    ~Folder();

    //将一条消息添加到当前 Folder 中，同时也需要将当前 Folder 添加到这个 Message 中
    void addMsg(Message *m) {
        messages.insert(m);
        add_to_message(*m);
    }
    //将一条消息添从当前 Folder 中删除，同时也需要将当前 Folder 从这个 Message 中删除
    void remMsg(Message *m) {
        messages.erase(m);
        if (m->folders.find(this) != m->folders.end())
            m->folders.erase(this);
    }

    void print();
};

#endif