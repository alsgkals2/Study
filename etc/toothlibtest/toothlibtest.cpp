// toothlibtest.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "vtkMatrix4x4.h"
struct TemplateNode
{
	TemplateNode()
	{
		_matrix = vtkMatrix4x4::New();
	}
	vtkMatrix4x4* _matrix;
	std::string id;
};
class ToothTemplate
{
public:
	ToothTemplate();
	~ToothTemplate();

public:
	void LoadTemplate(std::string path);
	TemplateNode* GetTemplateNode(int toothNum);
private:
	TOOTHTEMPLATEMAP m_templateMap;
};
void ToothTemplate::LoadTemplate(std::string path)
{
	//�ӽ� text ������ �д� ������ ��.
	std::list<std::string> _ret = GetFileList(path, ".txt");
	for each(auto iter in _ret)
	{
		TemplateNode* node = new TemplateNode();
		std::ifstream file(iter);
		std::string str;
		int count = 0;
		int i = 0;
		std::string _name = GetFileName(iter);
		while (std::getline(file, str))
		{
			if (str.length() == 0) continue;
			double _v = std::stod(str);
			node->id = str;
			node->_matrix->SetElement(count, i++, _v);
			if (i == 4)
			{
				i = 0;
				count++;
			}
		}
		m_templateMap.insert(TOOTHTEMPLATEMAP::value_type(std::stoi(_name), node));
	}
}

int main()
{
    return 0;
}

