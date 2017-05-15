//
// Created by Adrian on 2017-05-04.
//

#include "Serialization.h"

namespace academia {
    Room::Room(int id, const string &name, academia::Room::Type type) : id_(id), name_(name), type_(type) {}

    Building::Building(int id, string name, initializer_list<Room> rooms) {
        id_ = id;
        name_ = name;
        for (const auto &v : rooms) {
            room_.push_back(v);
        }
    }
    /*BuildingRepository::BuildingRepository(const vector<reference_wrapper<const Serializable>> building):building_{building}{}

    void BuildingRepository::Add(Building building){
        building_.emplace_back(building);
    }

    void BuildingRepository::StoreAll(JsonSerializer *serializer)const {
        serializer->Header("building_repository");
        serializer->ArrayField("buildings",building_);
        serializer->Footer("building_repository");

    }*/
    string Room::FindType() const {
        switch (type_) {
            case Type::COMPUTER_LAB:
                return "COMPUTER_LAB";
            case Type::LECTURE_HALL:
                return "LECTURE_HALL";
            case Type::CLASSROOM:
                return "CLASSROOM";
        }
    }

    //ROOM ----serialze
    void Room::Serialize(Serializer *serializer) {
        serializer->Header("room");
        serializer->IntegerField("id", id_);
        serializer->StringField("name", name_);
        serializer->StringField("type", FindType());
        serializer->Footer("room");
    }

    void Room::Serialize(XmlSerializer *xml) {
        xml->Header("room");
        xml->IntegerField("id", id_);
        xml->StringField("name", name_);
        xml->StringField("type", FindType());
        xml->Footer("room");
    }

    void Room::Serialize(JsonSerializer *json) {
        json->Header("room");
        json->IntegerField("id", id_);
        json->StringField("name", name_);
        json->StringField("type", FindType());
        json->Footer("}");
    }


    //Building...
    void Building::Serialize(XmlSerializer *xml) {
        xml->Header("building");
        xml->IntegerField("id", id_);
        xml->StringField("name", name_);
        xml->Header("rooms");
        for (auto &v : room_) {
            v.Serialize(xml);
        }
        xml->Footer("rooms");
        xml->Footer("building");
    }

    void Building::Serialize(JsonSerializer *json) {
        json->Header("building");
        json->IntegerField("id", id_);
        json->StringField("name", name_);
        json->AddOut("\"rooms\": [");
        int i = 0;
        for (auto &v : room_) {
            v.Serialize(json);
            i++;
            if (room_.size() > i) {
                json->AddOut(", ");
            }
        }
        json->Footer("]");
        json->Footer("}");
    }


    //XMLSERIZAER,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
    void XmlSerializer::IntegerField(const string &field_name, int value) {

        *out_ << string("<" + field_name + ">" + to_string(value) + "<\\" + field_name + ">");
    };

    void XmlSerializer::StringField(const string &field_name, const std::string &value) {

        *out_ << string("<" + field_name + ">" + value + "<\\" + field_name + ">");
    };

    void XmlSerializer::Header(const std::string &object_name) {
        *out_ << string("<" + object_name + ">");
    };

    void XmlSerializer::Footer(const std::string &object_name) {
        *out_ << string("<\\" + object_name + ">");

    };
//JSON SERALIZER

    void JsonSerializer::IntegerField(const string &field_name, int value) {

        *out_ << string("\"" + field_name + "\"" + ": " + to_string(value) + ", ");
    }

    void JsonSerializer::StringField(const string &field_name, const std::string &value) {
        string tmp1 = ", ";
        if (field_name == "type") {
            tmp1 = "";
        }
        *out_ << string("\"" + field_name + "\"" + ": " + "\"" + value + "\"");
        *out_ << tmp1;
    };

    void JsonSerializer::Header(const std::string &object_name) {
        *out_ << string("{");
    };

    void JsonSerializer::Footer(const std::string &object_name) {
        *out_ << object_name;
    };

    void JsonSerializer::AddOut(string input) {
        *out_ << input;
    }
    /*BuildingRepository::BuildingRepository(std::initializer_list<Building> elements) {
        for( auto n : elements){
            elements_.emplace_back(n);
        }
    }


    BuildingRepository::BuildingRepository() {
        elements_.clear();
    }

    /*void BuildingRepository::StoreAll(XmlSerializer *serializer) const {
        serializer->Header("building_repository");
        std::vector<std::reference_wrapper<const Serializable>> tmp;
        for(const Building &n : elements_){
            tmp.emplace_back(n);
        }
        serializer->ArrayField("buildings",tmp);
        serializer->Footer("building_repository");
    }

    void BuildingRepository::StoreAll(Serializer *serial) const {
        std::vector<std::reference_wrapper<const Serializable>> wrappers;
        serial->Header("building_repository");
        for(auto &it : elements_){
            wrappers.emplace_back(it);
        }
        serial->ArrayField("buildings", wrappers);
        serial->Footer("building_repository");
    }
    void BuildingRepository::Add(Building b) {
        elements_.emplace_back(b);
    }

    int Building::Id(void) const {
        return id_;
    }

    std::experimental::optional<Building> BuildingRepository::operator[](int id) const {
        for(auto &n : elements_){
            if(n.Id() == id){
                return std::experimental::make_optional(n);
            }
        }

        return experimental::optional<Building>();
    }*/

}