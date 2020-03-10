//This is a C++ program
//Designed and supported by Hodor
//High cohesion & Low coupling
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<ctime>
#include<cstdlib>

#define SALE_DEPATMENT 1        //销售部门
#define DEVELOP_DEPATMENT 2     //研发部门
#define FINANCIAL_DEPARTMENT 3  //财务部门

using namespace std;
//multimap案例
//公司今天招聘了5个员工，5名员工进入公司之后，需要指派员工在哪个部门工作
//人员信息：姓名，年龄，电话，工资
//通过multimap进行信息插入，保存和显示
//分部门显示员工信息 全部显示员工信息
//-------------------------------------------------------------------
/*1.创建员工后->要把员工存储起来->存到vector里->创建vector->确定vector类型->创建员工类
 *2.利用函数创建员工，把容器当做参数传进去，员工保存到容器中
 *3.利用函数在vector中进行员工分组，并把分完组的信息传到multimap中，将出入容器当做参数传入函数中
 *  利用相同部门的key值一样，使用multimap<int,Worker>保存，int保存组编号，Worker表示员工
 *4.打印每一个部门的员工信息
 */
//-------------------------------------------------------------------
class Worker {
public:
public:
    string mName;
    string mTele;
    int mAge;
    int mSalary;
};

void Create_Worker(vector<Worker>& vWorker) {
    string seedName("ABCDE");
    for (int i = 0; i < 5; ++i) {
        //创建员工
        Worker worker;

        worker.mName = "Worker ";
        worker.mName += seedName[i];

        worker.mTele = "010-88888888";
        worker.mAge = rand() % 10 + 20;
        worker.mSalary = rand() % 10000 + 10000;
        //保存员工信息
        vWorker.push_back(worker);
    }
}

void WorkerByGroup(vector<Worker>& vWorker, multimap<int,Worker>& workerGroup) {
    srand(time(NULL));
    for (vector<Worker>::iterator it = vWorker.begin(); it != vWorker.end(); ++it) {
        int departID = rand() % 3 + 1;
        switch (departID) {
        case SALE_DEPATMENT:
            workerGroup.insert(make_pair(FINANCIAL_DEPARTMENT, *it));
            break;
        case DEVELOP_DEPATMENT:
            workerGroup.insert(make_pair(DEVELOP_DEPATMENT, *it));
            break;
        case FINANCIAL_DEPARTMENT:
            workerGroup.insert(make_pair(FINANCIAL_DEPARTMENT, *it));
            break;
        default:
            break;
        }
    }
}

void ShowGroupWorkers(multimap<int, Worker>& workerGroup, int department) {
    multimap<int, Worker>::iterator it = workerGroup.find(department);
    int DepartCount = workerGroup.count(department);
    int num = 0;    //for初始化只能相同类型
    for (multimap<int, Worker>::iterator pos = it; it != workerGroup.end() && num < DepartCount; ++pos, ++num) {
        cout << "Name: " << (*pos).second.mName
            << " Tel: " << pos->second.mTele
            << " Age: " << pos->second.mAge
            << " Salary: " << pos->second.mSalary << endl;
    }
}

void PrintWorkerByGroup(multimap<int, Worker>& workerGroup) {
    //第一步：找到该key第一次出现的位置，然后从出现的位置处往后找，成员函数——fine(keyElem)，返回第一个的迭代器
    //第二步：需要知道每个key对应元素的个数，成员函数——count(keyElem)，返回key为该值的对组个数
    //第三步：对于每个部门，打印的步骤都一样，封装成函数
    
    cout << "SALE_DEPATMENT:" << endl;
    ShowGroupWorkers(workerGroup, SALE_DEPATMENT);
    
    cout << "DEVELOP_DEPATMENT:" << endl;
    ShowGroupWorkers(workerGroup, DEVELOP_DEPATMENT);
    
    cout << "FINANCIAL_DEPARTMENT:" << endl;
    ShowGroupWorkers(workerGroup, FINANCIAL_DEPARTMENT);
}

int main() {
    //1.存放员工的容器+员工类
    vector<Worker> vWorker;
    //2.创建员工函数
    Create_Worker(vWorker);
    //3.分组函数
    multimap<int, Worker> workerGroup;
    WorkerByGroup(vWorker, workerGroup);
    //4.打印每一部分的员工信息
    PrintWorkerByGroup(workerGroup);
    return 0;
}



