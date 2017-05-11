//
// Created by Adrian on 2017-05-04.
//

#ifndef JIMP_EXERCISES_SERIALIZATION_H
#define JIMP_EXERCISES_SERIALIZATION_H

#include<string>
#include <vector>
#include <functional>

using namespace std;
using namespace std::literals;

namespace academia {

    class Serializer;

    class JsonSerializer;

    class XmlSerializer;

    class Serializable {
    public:
        virtual void Serialize(Serializer *serializer) =0;

        virtual void Serialize(JsonSerializer *json) =0;

        virtual void Serialize(XmlSerializer *xml) =0;
    };
//serializer
    class Serializer {
    public:

        Serializer(std::ostream *out) : out_(out) {}

        virtual void IntegerField(const string &field_name, int value) {}

        virtual void DoubleField(const string &field_name, double value) {}

        virtual void StringField(const string &field_name, const string &value) {}

        virtual void BooleanField(const string &field_name, bool value) {}

        virtual void SerializableField(const string &field_name, const academia::Serializable &value) {}

        virtual void ArrayField(const string &field_name,
                                const vector<reference_wrapper<const academia::Serializable>> &value) {}

        virtual void Header(const string &object_name) {}

        virtual void Footer(const string &object_name) {}

    protected:
        ostream *out_;
    };

    class XmlSerializer {
    public:

        XmlSerializer(ostream *out) : out_(out) {}

        virtual void IntegerField(const string &field_name, int value);

        virtual void DoubleField(const string &field_name, double value) {};

        virtual void StringField(const string &field_name, const string &value);

        virtual void BooleanField(const string &field_name, bool value) {}

        virtual void SerializableField(const string &field_name, const academia::Serializable &value) {}

        virtual void ArrayField(const string &field_name,
                                const vector<reference_wrapper<const academia::Serializable>> &value) {}

        virtual void Header(const string &object_name);

        virtual void Footer(const string &object_name);

    protected:
        ostream *out_;

    };

    class JsonSerializer {
    public:

        JsonSerializer(ostream *out) : out_(out) {}

        virtual void IntegerField(const string &field_name, int value);

        virtual void DoubleField(const string &field_name, double value) {};

        virtual void StringField(const string &field_name, const std::string &value);

        virtual void BooleanField(const string &field_name, bool value) {}

        virtual void SerializableField(const string &field_name, const academia::Serializable &value) {}

        virtual void ArrayField(const string &field_name,
                                const vector<reference_wrapper<const academia::Serializable>> &value) {}

        virtual void Header(const string &object_name);

        virtual void Footer(const string &object_name);


        virtual void AddOut(string input);


    protected:
        ostream *out_;
    };


    class Room : public Serializable {
    public:

        enum Type {
            COMPUTER_LAB,
            LECTURE_HALL,
            CLASSROOM,
        };

        Room(int id, const string &name, Type type);

        string FindType() const;

        void Serialize(Serializer *serializer) override;

        void Serialize(XmlSerializer *xml) override;

        void Serialize(JsonSerializer *json) override;

    private:
        int id_;
        string name_;
        Type type_;
    };


    class Building : public Serializable {
    public:
        Building(int id, string name, std::initializer_list<Room> rooms);

        void Serialize(Serializer *serializer) override {}

        void Serialize(XmlSerializer *xml) override;

        void Serialize(JsonSerializer *json) override;


    private:
        int id_;
        string name_;
        vector<Room> room_;

    };
}
#endif //JIMP_EXERCISES_SERIALIZATION_H

