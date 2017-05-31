//
// Created by Adrian on 2017-05-04.
//
#include "Serialization.h"

using namespace std;
namespace academia {
    Serializer::Serializer(std::ostream *out) {
        out_ = out;
    }

    Room::Room(int id, const string &name, Room::Type type) {
        id_ = id;
        name_ = name;
        type_ = type;
    }

    string Room::TypeToString() const {
        switch (type_) {
            case Type::COMPUTER_LAB:
                return "COMPUTER_LAB";
            case Type::CLASSROOM:
                return "CLASSROOM";
            case Type::LECTURE_HALL:
                return "LECTURE_HALL";
        }
    }

    void Room::Serialize(Serializer *serializer) const {
        serializer->Header("room");
        serializer->IntegerField("id", id_);
        serializer->StringField("name", name_);
        serializer->StringField("type", TypeToString());
        serializer->Footer("room");
    }

    Building::Building(int id, string name, vector<Room> rooms) {
        for (auto n : rooms) {
            rooms_.emplace_back(n);
        }
        id_ = id;
        name_ = name;
    }

    void Building::Serialize(Serializer *serializer) const {
        serializer->Header("building");
        serializer->IntegerField("id", id_);
        serializer->StringField("name", name_);
        vector<std::reference_wrapper<const Serializable>> reference;
        for (const Room &n : rooms_) {
            reference.emplace_back(n);
        }
        serializer->ArrayField("rooms", reference);
        serializer->Footer("building");

    }

    int Building::Id(void) const {
        return id_;
    }

    XmlSerializer::XmlSerializer(std::ostream *out) : Serializer(out) {

    }

    void XmlSerializer::IntegerField(const std::string &field_name, int value) {
        *out_ << string("<") << field_name << string(">") << to_string(value) << string("<\\") << field_name
              << string(">");
    }

    void XmlSerializer::DoubleField(const std::string &field_name, double value) {
        *out_ << "<" + field_name + ">" + to_string(value) + "<\\" + field_name + ">";
    }

    void XmlSerializer::StringField(const std::string &field_name, const std::string &value) {
        *out_ << "<" + field_name + ">" + value + "<\\" + field_name + ">";
    }

    void XmlSerializer::BooleanField(const std::string &field_name, bool value) {
        *out_ << "<" + field_name + ">" + to_string(value) + "<\\" + field_name + ">";
    }

    void XmlSerializer::SerializableField(const std::string &field_name, const Serializable &value) {
        *out_ << "<" + field_name + ">";
        value.Serialize(this);
        *out_ << "<\\" + field_name + ">";
    }

    void XmlSerializer::ArrayField(const std::string &field_name,
                                   const vector<reference_wrapper<const Serializable>> &value) {
        Header(field_name);

        for (const Serializable &n : value) {
            n.Serialize(this);
        }

        Footer(field_name);
    }

    void XmlSerializer::Header(const std::string &object_name) {
        *out_ << "<" + object_name + ">";
    }

    void XmlSerializer::Footer(const std::string &object_name) {
        *out_ << "<\\" + object_name + ">";
    }


    JsonSerializer::JsonSerializer(std::ostream *output) : Serializer(output) {

    }

    void JsonSerializer::IntegerField(const std::string &field_name, int value) {
        NameWithInerpun(field_name);
        *out_ << to_string(value);
        PutField(", ");
    }

    void JsonSerializer::DoubleField(const std::string &field_name, double value) {
        NameWithInerpun(field_name);
        *out_ << to_string(value);
        PutField(", ");
    }

    void JsonSerializer::StringField(const std::string &field_name, const std::string &value) {
        NameWithInerpun(field_name);
        *out_ << "\"" + value + "\"";
        if (field_name != "type") {
            PutField(", ");
        }

    }

    void JsonSerializer::BooleanField(const std::string &field_name, bool value) {
        NameWithInerpun(field_name);
        *out_ << to_string(value);
        PutField(", ");
    }

    void JsonSerializer::SerializableField(const std::string &field_name, const Serializable &value) {
        NameWithInerpun(field_name);
        value.Serialize(this);
        PutField(", ");

    }

    void JsonSerializer::ArrayField(const std::string &field_name,
                                    const vector<reference_wrapper<const Serializable>> &value) {
        NameWithInerpun(field_name);
        *out_ << string("[");
        int i = 1;
        for (const Serializable &n : value) {
            n.Serialize(this);
            if (i != value.size()) {
                PutField(", ");
            }
            i++;
        }
        *out_ << string("]");
    }

    void JsonSerializer::Header(const std::string &object_name) {
        *out_ << string("{");
    }

    void JsonSerializer::Footer(const std::string &object_name) {
        *out_ << string("}");
    }

    void JsonSerializer::PutField(const std::string &field_put) {
        *out_ << field_put;
    }

    void JsonSerializer::NameWithInerpun(const std::string &field_name) {
        *out_ << "\"" + field_name + "\": ";
    }

    BuildingRepository::BuildingRepository() {
        buildings_.clear();
    }

    BuildingRepository::BuildingRepository(const std::initializer_list<Building> &elements) {
        for (auto &n : elements) {
            buildings_.emplace_back(n);
        }
    }

    void BuildingRepository::StoreAll(Serializer *serializer) const {
        vector<std::reference_wrapper<const Serializable>> reference;
        serializer->Header("building_repository");
        for (const Building &n : buildings_) {
            reference.emplace_back(n);
        }
        serializer->ArrayField("buildings", reference);
        serializer->Footer("building_repository");
    }

    void BuildingRepository::Add(const Building &building) {
        buildings_.emplace_back(building);
    }

    std::experimental::optional<Building> BuildingRepository::operator[](int id) const {
        for (auto &n : buildings_) {
            if (n.Id() == id) {
                return std::experimental::make_optional(n);
            }
        }

        return experimental::optional<Building>();//Pusty
    }
}