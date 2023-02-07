#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Department.h"

using namespace std;

namespace sdds {

    void Department::updateName(const char* newname)
    {
        if (newname != NULL && newname[0] != '\0')
        {
            if (m_dName)
            {
                delete[] m_dName;
            }
            m_dName = new char[strlen(newname) + 1];
            strcpy(m_dName, newname);
        }
    }

    void Department::updateBudget(double change)
    {
        m_budget += change;
    }

    bool Department::addProject(Project& newproject)
    {
        bool success;
       
        if ((totalexpenses() + newproject.m_cost) <= m_budget)
        {
            if (m_numOfCurrentProject == 0)
            {
                m_project = new Project[1];                     // new keyword apply for place in main memory, so need to delete after use
                *m_project = newproject;
            }
            else
            {
                Project* temp = nullptr;                        // when work, we will use chain instead of this method. it's too slow.
                temp = new Project[m_numOfCurrentProject + 1];
                for (int i = 0; i < m_numOfCurrentProject; i++)
                {
                    temp[i] = m_project[i];
                }
                temp[m_numOfCurrentProject] = newproject;

                delete[] m_project;
                m_project = nullptr;
                m_project = temp;   // temp is in heap (between {}), so the 4 bytes for temp do not need to delete. 
                                    // temp and m_project point to the same place in main memory  
                                    // once delete[] m_project, the place is released. so do not need to delete[] temp.
                                    
            }
            m_numOfCurrentProject += 1;
            success =  true;
        }
        else
        {
           success = false;
        }
        return success;
    }

    void Department::createDepartment(const char* newname,
        Project& newproject,
        double change)
    {
        updateName(newname);
        addProject(newproject);
        updateBudget(change);   
    }
    Project* Department::fetchProjects() const
    {
        return m_project;
    }
    int Department::fetchNumProjects() const
    {
        return m_numOfCurrentProject;
    }
    double Department::fetchBudget() const
    {
        return m_budget;
    }
    char* Department::fetchName() const
    {
        return m_dName;
    }
    double Department::totalexpenses()
    {
        double totalCost = 0;
        for (int i = 0; i < m_numOfCurrentProject; i++)
        {
            totalCost += m_project[i].m_cost;
        }
        return totalCost;
    }
    double Department::remainingBudget()
    {
        return m_budget - Department::totalexpenses();
    }
    void Department::clearDepartment()
    {
        delete[] m_dName;   // important to delete before set it to nullptr
        m_dName = nullptr;
        delete[] m_project;  // important to delete before set it to nullptr
        m_project = nullptr;
        m_numOfCurrentProject = 0;
        m_budget = 0;
    }

    //fully provided for students to display details of a project
    void display(const Project& project) {
        cout << "Project " << project.m_topic
            << " will cost a total of " << project.m_cost << " C$." << endl;
    }

    //fully provided for students to display details of a department
    void display(const Department& department) {
        Project* temp = department.fetchProjects();
        int projects = department.fetchNumProjects();
        cout << "Department " << department.fetchName() << " details:" << endl;
        cout << "Budget: " << department.fetchBudget()
            << " and the number of projects in progress is: " << projects << endl;
        cout << "Below are the details of the projects we are currently working on: " << endl;
        for (int i = 0; i < projects; i++) {
            display(temp[i]);
        }
    }

}