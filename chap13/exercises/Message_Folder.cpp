#include "Message_Folder.h"

void Message::add_to_Folders(const Message &m) {
    for (auto f : m.folders)  //对每个包含 m 的 Folder
        f->addMsg(this);      //向该 Folder 添加一个指向本 Message 的指针
}

void Message::remove_from_Folders() {
    for (auto f : folders)  //对 folders 中的每个指针
        f->remMsg(this);    //从该 Folder 中删除本 Message
}

Message::Message(const Message &m) : contents(m.contents), folders(m.folders) {
    add_to_Folders(m);  //将本消息添加到指向 m 的 Folder 中
}

Message::~Message() {
    remove_from_Folders();
}

Message &Message::operator=(const Message &rhs) {
    //通过先删除指针再插入它们来处理自赋值情况
    remove_from_Folders();    //更新已有 Folder
    contents = rhs.contents;  //从 rhs 拷贝消息内容
    folders = rhs.folders;    //从 rhs  拷贝 Folder 指针
    add_to_Folders(rhs);      //将本 Message 添加到那些 Folder 中
    return *this;
}

void Message::save(Folder &f) {
    folders.insert(&f);  //将给定 Folder 添加到我们的 Folder 列表中
    f.addMsg(this);      //将本 Message 添加到 f 的 Message 集合中
}

void Message::remove(Folder &f) {
    folders.erase(&f);  //将给定 Folder 从我们的 Folder 列表中删除
    f.remMsg(this);     //将本 Message 从 f 的 Message 集合中删除
}

void swap(Message &lhs, Message &rhs) {
    using std::swap;  //在本例中严格来说不需要，但这是一个好习惯
    //将每个消息的指针从它（原来）所在的 Folder 中删除
    for (auto f : lhs.folders)
        f->remMsg(&lhs);

    for (auto f : rhs.folders)
        f->remMsg(&rhs);

    //交换 contents 和 Folder 指针 set
    swap(lhs.folders, rhs.folders);    //使用 swap(set&, set&)
    swap(lhs.contents, rhs.contents);  //使用 swap(string&, string&)
    //将每个 Message 的指针添加到它的（新的）Folder 中
    for (auto f : lhs.folders)
        f->addMsg(&lhs);

    for (auto f : rhs.folders)
        f->addMsg(&rhs);
}

void Message::print() {
    std::cout << "当前消息内容为：" << contents << "，该消息存在于 " << folders.size() << " 个 Folder 中" << std::endl;
}

//-------------------------------------------------------

Folder::Folder(const Folder &f) : messages(f.messages) {
    add_to_messages();
}

Folder &Folder::operator=(const Folder &rhs) {
    remove_from_messages();
    messages = rhs.messages;
    add_to_messages();

    return *this;
}

Folder::~Folder() {
    remove_from_messages();
}

void swap(Folder &lhs, Folder &rhs) {
    using std::swap;
    lhs.remove_from_messages();
    rhs.remove_from_messages();

    swap(lhs.messages, rhs.messages);

    lhs.add_to_messages();
    rhs.add_to_messages();
}

void Folder::print() {
    std::cout << "当前 Folder 公有 " << messages.size() << " 条消息，分别为：" << std::endl;
    for (auto m : messages)
        std::cout << "当前消息内容为：" << m->contents << "，该消息存在于 " << m->folders.size() << " 个 Folder 中" << std::endl;
}