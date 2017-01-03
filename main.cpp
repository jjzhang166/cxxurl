#include <iostream>

#include "include/CXXUrl.h"
#include <iostream>
#include <sstream>
#include <fstream>


using namespace CXXUrl;
using namespace std;

int main() {

    ostringstream headerOutput;
//    ofstream contentOutput;
//    contentOutput.open("/Users/xiaozhuai/Desktop/content.html");
    ostringstream contentOutput;


    SimpleForm simpleForm;
    simpleForm.add("username", "admin");
    simpleForm.add("password", "benquwangluo@2015");

    MultipartForm multipartForm;
    multipartForm.add("username", "admin");
    multipartForm.add("password", "benquwangluo@2015");
    multipartForm.addFile("file1", "/Users/xiaozhuai/Desktop/actor_output/male_chenweiting.png");
    multipartForm.addFile("file2", "/Users/xiaozhuai/Desktop/actor_output/male_gd.png");

    RawForm rawForm;
    rawForm.setRawText("hello world");

    RequestBuilder builder;
    builder.url("http://localhost:10000/public/test_form.php")
            .followLocation(true)
            .query("bbb", "222")
            .query("ccc", "333")
            .form(&simpleForm)
//            .form(&multipartForm)
//            .form(&rawForm)
            .headerOutput(&headerOutput)
            .contentOutput(&contentOutput);

    Request& request = builder.build();
    CURLcode res = request.post();

//    contentOutput.flush();
//    contentOutput.close();


//    cout << "[code]\n" << res << "\n\n[header]\n" << headerOutput.str() << endl;
    cout << "[code]\n" << res << "\n\n[header]\n" << headerOutput.str() << "\n\n[content]\n" << contentOutput.str() << endl << flush;


    return 0;
}