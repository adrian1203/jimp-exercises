#include "Serialization.h"
#include <cstdint>
#include <cassert>
#include <string>
#include <vector>
#include <functional>
using namespace std;
namespace academia {
    //ROOM I buliding KONSTRUKTORY,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
    Room::Room(int id, const string &name, academia::Room::Type type) : id_(id), name_(name), type_(type) {}
    Building::Building(int id, const string &name, const vector<reference_wrapper<const Serializable>> room) :id_{id}, name_{name}, room_{room} {}
    string Room::FindType()const{
        switch (type_) {
            case Type::COMPUTER_LAB:
                return "COMPUTER_LAB";
            case Type::LECTURE_HALL:
                return "LECTURE_HALL";
            case Type::CLASSROOM:
                return "CLASSROOM";
        }
    }
    //ROOM I BULDING SERIZALZER
    void Room::Serialize(Serializer *serializer)const {
        serializer->Header("room");
        serializer->IntegerField("id", id_);
        serializer->StringField("name", name_);
        serializer->StringField("type", FindType());
        serializer->Footer("room");
    }
    void Building::Serialize(Serializer *serializer)const {
        serializer->Header("building");
        serializer->IntegerField("id", id_);
        serializer->StringField("name", name_);
        serializer->ArrayField("rooms",room_);
        serializer->Footer("building");
    }
    //XMLSERIZAER,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
    void XmlSerializer::IntegerField(const string &field_name, int value){

        *out_ << string("<" + field_name + ">" + to_string(value) + "<\\" + field_name + ">");
    };
    void XmlSerializer::DoubleField(const string &field_name, double value){

    }
    void XmlSerializer::StringField(const string &field_name, const std::string &value){

        *out_ << string("<" + field_name + ">" + value + "<\\" + field_name + ">");
    };
    void XmlSerializer::BooleanField(const string &field_name, bool value){

    };
    void XmlSerializer::SerializableField(const string &field_name, const academia::Serializable &value){

    };
    void XmlSerializer::ArrayField(const string &field_name,
                                   const vector<reference_wrapper<const academia::Serializable>> &value){
        XmlSerializer::Header(field_name);
        for(const auto &n : value){
            n.get().Serialize(this);
        }
        XmlSerializer::Footer(field_name);

    };
    void XmlSerializer::Header(const std::string &object_name){

        *out_ << string("<" + object_name + ">");
    };
    void XmlSerializer::Footer(const std::string &object_name){

        *out_ << string("<\\" + object_name + ">");

    };
    //JSONSERIZALZER
    void JsonSerializer::IntegerField(const string &field_name, int value){
        *out_ << string("\"" + field_name + "\"" + ": " + to_string(value) + ", ");
    };
    void JsonSerializer::DoubleField(const string &field_name, double value){

    }
    void JsonSerializer::StringField(const string &field_name, const std::string &value){

        string tmp1 = ", ";
        if (field_name == "type") {
            tmp1 = "";
        }
        *out_ << string("\"" + field_name + "\"" + ": " + "\"" + value + "\"");
        *out_ << tmp1;
    };
    void JsonSerializer::BooleanField(const string &field_name, bool value){

    };
    void JsonSerializer::SerializableField(const string &field_name, const academia::Serializable &value){

    };
    void JsonSerializer::ArrayField(const string &field_name,
                                    const vector<reference_wrapper<const academia::Serializable>> &value){
        *out_<<string("\"")<<field_name<<string("\": [");
        int a=value.size();
        int i=1;
        for(auto const &n:value){
            n.get().Serialize(this);
            if(i!=a)*out_<<string(", ");
            i++;
        }
        *out_<<string("]");
    };
    void JsonSerializer::Header(const std::string &object_name){
        *out_<<string("{");
    };
    void JsonSerializer::Footer(const std::string &object_name){
        *out_<<string("}");
    };

}