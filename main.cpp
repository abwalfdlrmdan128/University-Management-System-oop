#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Department {
protected:
    string name;
    int capacity;
    double required_gpa;
    public:
    Department() {
        name = "";
        capacity = 0;
        required_gpa = 0;
    }
    Department(string name, int capacity, double required_gpa) {
        this->name = name;
        this->capacity = capacity;
        this->required_gpa = required_gpa;
    }
    void setName(string name) {
        this->name = name;
    }
    void setCapacity(int capacity) {
        this->capacity = capacity;
    }
    void setRequiredGpa(double requiredGpa) {
        this->required_gpa = requiredGpa;
    }
    string getName() {
        return name;
    }
    int getCapacity() {
        return capacity;
    }
    double getRequiredGPa() {
        return required_gpa;
    }
    ~Department() {}
};
class Person {
    protected:
    string name;
    int age;
    int Id;
    string gender;
    public:
    Person() {};
    Person(string name, int age, int Id) : name(name), age(age), Id(Id) {}
    string getName() const{
        return name;
    }
    int getAge() const{
        return age;
    }
    int getId() const{
        return Id;
    }
    string get_gender() {
        return gender;
    }
    void Display_ditails() {
        cout<<"Person Details: "<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Id: "<<Id<<endl;
        cout<<"Gender: "<<gender<<endl;
    }
    ~Person() {}
};
class Student : public Person {
    int level;
    double GPA;
    public:
    Student() {}
    Student(int id,string name,int age,char gender,int level,double gpa) {
        this->name = name;
        this->age = age;
        this->level = level;
        this->GPA = gpa;
        this->gender = gender;
        this->Id = id;
    }
    void setGPA(double gpa) {
        this->GPA = gpa;
    }
    double getGPA() {
        return this->GPA;
    }
    void setLevel(int level) {
        this->level = level;
    }
    int getLevel() {
        return level;
    }
    void Display_ditails() {
        Person::Display_ditails();
        cout<<"Level: "<<level<<endl;
        cout<<"GPA: "<<GPA<<endl;
    }
    ~Student() {}
};
class Professor : public Person {
    double salary;
    string degree;
    Department *department;
    public:
    Professor() {}
    Professor(int id,string name,int age,char gender,double salary,string degree,Department *depart) {
        this->name = name;
        this->age = age;
        this->department = depart;
        this->salary = salary;
        this->degree = degree;
        this->Id=id;
        this->gender = gender;
    }
    void setSalary(double salary) {
        this->salary = salary;
    }
    double getSalary() {
        return this->salary;
    }
    void setDegree(string degree) {
        this->degree = degree;
    }
    string getDegree() {
        return this->degree;
    }
    void display_ditails() {
        Person::Display_ditails();
        cout<<"Salary: "<<salary<<endl;
        cout<<"Degree: "<<degree<<endl;
    }
};
class Course {

    string name;
    string code;
    int hours;
    vector<Course*> prerequisites;
    vector<Student*> students;
    Professor *professor;

public:
    Course() {
        name = "";
        code = "";
        hours = 0;
        prerequisites={};
    }
    Course(string name,string code,int hours,vector<Course*>pre,Professor *pro,vector<Student*>students) {
        this->name = name;
        this->code = code;
        this->prerequisites=pre;
        this->students=students;
        this->hours = hours;
        this->professor = pro;
    }
    void set_name(string s)
    {
        name = s;
    }
    void set_code(string s)
    {
        code = s;
    }
    void set_hours(int a)
    {
        hours = a;
    }
    void set_professor(Professor *p)
    {
        professor = p;
    }

    void set_students(vector<Student*> s)
    {
        students = s;
    }
    void set_prerequisites(vector<Course*>c)
    {
        prerequisites=c;

    }
    string get_name()
    {
        return name;
    }
    string get_code()
    {
        return code;
    }
    int get_hours()
    {
        return hours;
    }
    Professor *get_professor()
    {
        return professor;
    }
    vector<Student*> get_students()
    {
        return students;
    }
    vector<Course*> get_prerequisites()
    {

        return prerequisites;
    }
    void print_name()
    {
        cout << name << endl;
    }
    void print_code()
    {
        cout << code << endl;
    }
    void print_hours()
    {
        cout << hours << endl;
    }
    ~Course(){}
};
class university {
    static university *ptr;
    university(){addData();};
    vector<Course> courses;
    vector<Student> students;
    vector<Professor> professors;
    vector<Department> departments;
public:
    university(const university &obj)=delete;
    static university *get_ptr()
    {
        if (ptr == NULL)
        {
            ptr = new university();
        }
        return ptr;
    }
    void Add_Course(string name,string code,int hours,vector<Course*>pre,vector<Student*>students,Professor*prof) {
      //Course(name,code,hours,pre,prof,students);
        courses.push_back(Course(name,code,hours,pre,prof,students));
    }
    void Remove_Course(string code)
    {
        for (int i = 0; i < courses.size(); i++)
        {
            if (courses[i].get_code() == code)
            {
                courses.erase(courses.begin() + i);
            }
        }
    }
    void Update_Course(string code, int hours)
    {
        for (int i = 0; i < courses.size(); i++)
        {
            if (courses[i].get_code() == code)
            {
                courses[i].set_hours(hours);
                return;
            }
        }
        cout << "course with code " << code << " not found." << endl;
    }


    void Add_Student(int ID,string name,int age,char gender, int level, double GPA)
    {
        Student student(ID, name,  age,gender,  level,  GPA);
        students.push_back(student);
    }
    void Remove_Student(int id)
    {
        for (int i = 0; i < students.size(); i++)
        {
            if (students[i].getId() == id)
            {
                students.erase(students.begin() + i);
                return;
            }
        }
        cout << "Student with ID " << id << " not found." << endl;
    }



    void Update_Student(int id,int level)
    {
        for (int i=0;i<students.size();i++)
        {
            if (students[i].getId() == id)
            {
                students[i].setLevel(level);
                return;
            }
        }
        cout << "Student with ID " << id << " not found." << endl;
    }
    void Add_Professor(int ID,string name, int age,char gender,Department *department,  double salary, string degree)
    {
        Professor professor(ID, name, age, gender,salary,degree, department);
        professors.push_back(professor);
    }
    void Remove_Professor(int id)
    {
        for (int i = 0; i < professors.size(); i++)
        {
            if (professors[i].getId() == id)
            {
                professors.erase(professors.begin() + i);
                return;
            }
        }
        cout << "Professor with ID " << id << " not found." << endl;
    }

    void Update_Professor(int id, int s)
    {
        for (int i = 0; i < professors.size(); i++)
        {
            if (professors[i].getId() == id)
            {
                professors[i].setSalary(1);return;
            }
        }
        cout << "Professor with ID " << id << " not found." << endl;
    }

    void Add_Department(string name, int capacity, double required_gpa)
    {
        Department department(name,capacity,required_gpa);
        departments.push_back(department);
    }

    void Remove_Department(string name)
    {
        for (int i = 0; i < departments.size(); i++)
        {
            if (departments[i].getName() == name)
            {
                departments.erase(departments.begin() + i);
                return;
            }
        }
        cout << "Department with name " << name << " not found." << endl;
    }
    void Update_Department(string name, int c)
    {
        for (int i = 0; i < departments.size(); i++)
        {
            if (departments[i].getName() == name)
            {
                professors[i].setSalary(c);// or change the required GPA
            }
        }
    }
    void addData()
    {
        Department d1("Web Development", 50, 3.2);
        departments.push_back(d1);
        Department d2("Cyber Security", 33, 3.5);
        departments.push_back(d2);
        Department d3("Artificial Intelligence", 20, 3.0);
        departments.push_back(d3);
        Department d4("Information Systems", 125, 2.5);
        departments.push_back(d4);

        Student s1(1,"fadell Ali", 19, 'M', 2, 2.74);
        students.push_back(s1);
        Student s2(2,"mohammed Hussein", 22, 'M', 4, 3.68);
        students.push_back(s2);
        Student s3(3,"Hamada Hossam", 28, 'M', 3, 2.37);
        students.push_back(s3);
        Student s4(4,"mostafa Mohsen", 20, 'M', 3, 3);
        students.push_back(s4);
        Student s5(5,"ali Belal", 18, 'M', 1, 3.71);
        students.push_back(s5);
        Student s6(6,"khalid Diab", 50, 'M', 4, 2.01);
        students.push_back(s6);
        Student s7(7,"Tamer Hosny", 30, 'M', 3, 2.02);
        students.push_back(s7);
        Student s8(8,"amr Alaa", 21, 'M', 2, 2.49);
        students.push_back(s8);

        Professor p1(1,"Mohamed Ali", 56, 'M', 12000,"Masters", &d1);
        professors.push_back(p1);
        Professor p2(2,"Ehsan Ahmed", 43, 'M',8500,"Masters",&d2);
        professors.push_back(p2);
        Professor p3(3,"Ahmed Mohsen", 68, 'M',4500,"Masters",&d3);
        professors.push_back(p3);
        Professor p4(4,"Abdelhady", 61, 'M',7500,"Masters", &d4);
        professors.push_back(p4);
        Professor p5(5,"Taghreed Mohsen", 49, 'F',9000,"Masters",&d4);
        professors.push_back(p5);


        vector<Student*> st1;
        st1.push_back(&s1);
        st1.push_back(&s2);
        st1.push_back(&s3);
        st1.push_back(&s4);
        vector<Student*> st2;
        st2.push_back(&s5);
        st2.push_back(&s6);
        st2.push_back(&s7);
        st2.push_back(&s8);
        Course c1("HTML", "HTML123", 12, vector<Course*>(), &p1, st1);
        courses.push_back(c1);
        vector<Course*> crs1;
        crs1.push_back(&c1);
        Course c2("CSS", "CSS123", 9, crs1,&p3, st2);
        courses.push_back(c2);
        Course c3("Networks", "Net521", 18, crs1, &p5, st2);
        courses.push_back(c3);
    }

    void printAll()
    {
        for(int i=0; i<departments.size(); i++)
        {
            cout<<"Department: "<<departments[i].getName()<<endl;
        }
        for(int i=0; i<professors.size(); i++)
        {
            cout<<"Professor Name: "<<professors[i].getName()<<endl;
        }
        for(int i=0; i<students.size(); i++)
        {
            cout<<"Student Name: "<<students[i].getName()<<endl;
        }
        for(int i=0; i<courses.size(); i++)
        {
            cout<<"Course Name: "<<courses[i].get_name()<<endl;
        }
    }
    ~university(){};
};
university* university::ptr=NULL;
int main() {
university* ptr=university::get_ptr();
    ptr->printAll();
    return 0;
}