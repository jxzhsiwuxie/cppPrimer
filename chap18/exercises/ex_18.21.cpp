//练习 18.21：解释下列声明的含义，在它们当中存在错误么？如果有，请指出来并说明原因。
// (a) class CADVehicle : public CAD, Vehicle { ... };
// (b) class DblList: public List, public List { ... };
// (c) class iostream: public istream, public ostream { ... };

/*
* (a) CADVehicle 公有继承 CAD 同时私有继承 Vehicle
* (b) 错误，在一个继承列表中，同一个类只能出现一次
* (c) iostream 公有继承 istream 同时又公有继承 ostream
*/
