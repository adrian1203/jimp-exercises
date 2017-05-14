#ifndef JIMP_EXERCISES_SERIALIZATION_H
#define JIMP_EXERCISES_SERIALIZATION_H
#include <string>
#include <vector>
#include <functional>
#include <cstdint>
#include <cassert>
using namespace std;
namespace academia{
    class Serializer;
    class XmlSerializer;
    class BuildingRepository;
    class Serializable{
    public:
        virtual void Serialize(Serializer *out)const=0;


    };
    class Serializer{
    public:
        Serializer(std::ostream *out): out_(out){};
        virtual void IntegerField(const string &field_name, int value) = 0;
        virtual void DoubleField(const string &field_name, double value) = 0;
        virtual void StringField(const string &field_name, const std::string &value) = 0;
        virtual void BooleanField(const string &field_name, bool value) = 0;
        virtual void SerializableField(const string &field_name, const academia::Serializable &value)=0;
        virtual void ArrayField(const string &field_name,
                                const vector<reference_wrapper<const academia::Serializable>> &value)=0;
        virtual void Header(const std::string &object_name)=0;
        virtual void Footer(const std::string &object_name)=0;
    protected:
        ostream *out_;
    };
    class XmlSerializer :public Serializer{
    public:
        XmlSerializer(std::ostream *out): Serializer(out){};
        void IntegerField(const string &field_name, int value) override ;
        void DoubleField(const string &field_name, double value) override ;
        void StringField(const string &field_name, const std::string &value) override ;
        void BooleanField(const string &field_name, bool value) override ;
        void SerializableField(const string &field_name, const academia::Serializable &value) override ;
        void ArrayField(const string &field_name,
                        const vector<reference_wrapper<const academia::Serializable>> &value) override ;
        void Header(const std::string &object_name)override ;
        void Footer(const std::string &object_name)override ;


        ;
    };
    class JsonSerializer : public Serializer{
    public:
        JsonSerializer(std::ostream *out):Serializer(out){};
        void IntegerField(const string &field_name, int value) override ;
        void DoubleField(const string &field_name, double value) override ;
        void StringField(const string &field_name, const std::string &value) override ;
        void BooleanField(const string &field_name, bool value) override ;
        void SerializableField(const string &field_name, const academia::Serializable &value) override ;
        void ArrayField(const string &field_name,
                        const vector<reference_wrapper<const academia::Serializable>> &value) override ;
        void Header(const std::string &object_name)override ;
        void Footer(const std::string &object_name)override ;



    };
    class Room :public Serializable{
    public:
        enum class Type{
            COMPUTER_LAB,
            LECTURE_HALL,
            CLASSROOM
        };
        Room(int id, const string &name, Type type);
        void Serialize(Serializer *serializer) const override;
        string FindType() const;

    public:
        int id_;
        string name_;
        Type type_;

    };
    class Building:public Serializable{
    public:
        Building(int id, const string &name, const vector<reference_wrapper<const Serializable>> room_);
        void Serialize(Serializer *serializer) const override ;
        int GetId() { return id_; }
        std::string GetName() { return name_; }
    private:
        int id_;
        string name_;
        const vector<reference_wrapper<const Serializable>> room_;


    };
    class BuildingRepository{

    };
}

#endif //JIMP_EXERCISES_SERIALIZATION_H
