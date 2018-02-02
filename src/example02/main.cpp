#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <vector>
#include <map>
#include <cassert>

#include "CJay.hpp"
//#include "example/Example.hpp"

#define MAX_TOLERANCE 1.0e-4

jint VM::CJ::JNI_VERSION = DEFAULT_JNI_VERSION; // Depends on installed JDK!

using namespace VM;

int main(int argc, char* argv[]) {
	// Create JVM
	std::vector<std::string> paramVM{ "-Djava.compiler=NONE", "-ea", "-Xdebug", "-Djava.library.path=\".\";joda-time-2.2.jar;hanlp-portable-1.5.3.jar;" };
	VM::createVM(paramVM, L"C:\\Java\\jdk\\jre\\bin\\server\\jvm.dll");
	//VM::createVM();

	CJ CJ;

	// Set class
	try {
		CJ.setClass("hello/HelloWorld");
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
		VM::destroyVM();
		return EXIT_FAILURE;
	}

	CJ.printSignatures();

	
		
	jclass HelloClass = CJ.getEnv()->FindClass("hello/HelloWorld");
	if (HelloClass) {
		// Find the main method id  
		jmethodID Hello_main = CJ.getEnv()->GetStaticMethodID(HelloClass, "main", "([Ljava/lang/String;)V");
		if (Hello_main) {
			// Call the main method.  
			CJ.getEnv()->CallStaticVoidMethod(HelloClass, Hello_main);
		}
	}

	//CJ.call<void>("main");

	/*jmethodID main_id = CJ.getMid("main");

	if (main_id) {
	printf("111111111111\n");
	CJ.callStatic(main_id, );
	}*/

	//CJ.callStatic(main_id);

	//// Print signatures
	//CJ.printSignatures();

	//// Call constructor
	//try {
	//	CJ.Constructor("<init>"); // contructor has no parameters
	//}
	//catch (std::exception& e) {
	//	std::cout << e.what() << std::endl;
	//	VM::destroyVM();
	//	return EXIT_FAILURE;
	//}



	// Destroy VM
	VM::destroyVM();

	return EXIT_SUCCESS;
}