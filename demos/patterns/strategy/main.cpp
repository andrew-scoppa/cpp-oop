#include <iostream>
#include <fstream>
#include <vector>

using std::cout, std::endl;

class IReportStrategy
{
public:
    virtual void RenderTitle(std::string title) = 0;
    virtual void RenderHeadings(std::vector<std::string> headings) = 0;
    virtual void RenderRows(std::vector<std::vector<std::string>> rows) = 0;
    virtual void RenderFooter(std::string title) = 0;

    virtual ~IReportStrategy() {}
};

class TextReportStrategy : public IReportStrategy
{
private:
    std::ofstream _ofs;
    std::string _filename;

public:
    TextReportStrategy(std::string filename) : _filename(filename)
    {
        _ofs.open(_filename);
    }
    void RenderTitle(std::string title)
    {
        _ofs << title << endl;
    }
    void RenderHeadings(std::vector<std::string> headings)
    {
        for (std::vector<std::string>::iterator it = headings.begin(); it < headings.end(); ++it)
        {
            _ofs << *it << '\t';
        }
        _ofs << endl;
    }
    void RenderRows(std::vector<std::vector<std::string>> rows)
    {
        for (auto &row : rows)
        {
            for (std::vector<std::string>::iterator it = row.begin(); it < row.end(); ++it)
            {
                _ofs << *it << '\t';
            }
            _ofs << endl;
        }
        _ofs << endl;
    }
    void RenderFooter(std::string title)
    {
        _ofs << title << endl;
    }

    ~TextReportStrategy()
    {

        _ofs.close();
    }
};

/*
 * IReportTemplate implements a template method defining the skeleton of an algorithm
 */
class IReportTemplate
{
private:
protected:
    virtual std::string GetTitle() = 0;
    virtual std::vector<std::string> GetHeadings() = 0;
    virtual std::vector<std::vector<std::string>> GetRows() = 0;
    virtual std::string GetFooter() = 0;

public:
    void templateMethod(IReportStrategy *strategy)
    {
        strategy->RenderTitle(GetTitle());

        strategy->RenderHeadings(GetHeadings());

        strategy->RenderRows(GetRows());

        strategy->RenderFooter(GetFooter());
    }

    virtual ~IReportTemplate() {}
};

/*
 * CompanyReport implements the primitive operations to carry out specific steps
 * of the algorithm, there may be many Concrete classes, each implementing
 * the full set of the required operation
 */
class CompanyReport : public IReportTemplate
{
protected:
    std::string GetTitle() override
    {
        return "Scoppa Software Solutions, LLC";
    }

    std::vector<std::string> GetHeadings() override
    {
        std::vector<std::string> headings;
        headings.push_back("SKU");
        headings.push_back("PRICE");
        return headings;
    }

    std::vector<std::vector<std::string>> GetRows() override
    {
        std::vector<std::vector<std::string>> rows;
        rows.push_back(std::vector<std::string>{"a01d", "$12.99"});
        rows.push_back(std::vector<std::string>{"a7cd", "$15.99"});
        rows.push_back(std::vector<std::string>{"a9cb", "$18.99"});
        return rows;
    }

    std::string GetFooter() override
    {
        return "All rights reserved";
    }

public:
    ~CompanyReport() {}
};

int main()
{
    IReportStrategy *rs = new TextReportStrategy("report.txt");
    IReportTemplate *tm = new CompanyReport();

    tm->templateMethod(rs);

    delete rs;
    delete tm;

    return 0;
}
