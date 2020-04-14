#ifndef TESTS_H_INCLUDED
#define TESTS_H_INCLUDED

#include "Product.h"
#include "Monede.h"
#include "RepoTemplate.h"
#include "RepoSTL.h"
#include "Service.h"

class Test
{
private:
	void testProducts();
	void testGetter();
	void testSetter();
	void testMonede();
	void testMonedeGetter();
	void testMonedeSetter();
	void testRepoTemplate();
	void testRepoTemplateAdd();
	void testRepoTemplateDel();
	void testRepoTemplateUpdate();
	void testRepoTemplateGetAll();
	void testRepoSTL();
	void testRepoSTLAdd();
	void testRepoSTLDel();
	void testRepoSTLUpdate();
	void testService();
	void testServiceAdd();
	void testServiceDelete();
	void testServiceUpdate();
	void testServiceBuyProduct();
public:
	Test();
	~Test();
	void runTests();

};


#endif // TESTS_H_INCLUDED
