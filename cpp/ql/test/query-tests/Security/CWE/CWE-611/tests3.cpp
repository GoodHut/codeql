// test cases for rule CWE-611 (SAX2XMLReader)

#include "tests.h"

// ---

class SAX2XMLReader
{
public:
	void setFeature(const XMLCh *feature, bool value);
	void parse(const InputSource &data);
};

class XMLReaderFactory
{
public:
	static SAX2XMLReader *createXMLReader();
};

// ---

void test3_1(InputSource &data) {
	SAX2XMLReader *p = XMLReaderFactory::createXMLReader();

	p->parse(data); // BAD (parser not correctly configured) [NOT DETECTED]
}

void test3_2(InputSource &data) {
	SAX2XMLReader *p = XMLReaderFactory::createXMLReader();

	p->setFeature(XMLUni::fgXercesDisableDefaultEntityResolution, true);
	p->parse(data); // GOOD
}

SAX2XMLReader *p_3_3 = XMLReaderFactory::createXMLReader();

void test3_3(InputSource &data) {
	p_3_3->parse(data); // BAD (parser not correctly configured) [NOT DETECTED]
}

SAX2XMLReader *p_3_4 = XMLReaderFactory::createXMLReader();

void test3_4(InputSource &data) {
	p_3_4->setFeature(XMLUni::fgXercesDisableDefaultEntityResolution, true);
	p_3_4->parse(data); // GOOD
}

SAX2XMLReader *p_3_5 = XMLReaderFactory::createXMLReader();

void test3_5_init() {
	p_3_5->setFeature(XMLUni::fgXercesDisableDefaultEntityResolution, true);
}

void test3_5(InputSource &data) {
	test3_5_init();
	p_3_5->parse(data); // GOOD
}
