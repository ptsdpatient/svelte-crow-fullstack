#define CROW_MAIN

#include <libpq-fe.h>
#include "crow.h"
#include <iostream>
#include "./db/queries.h"


constexpr uint16_t PORT = 2000;

using std::string;
using crow::SimpleApp;
using crow::request;
using crow::LogLevel;
using json = crow::json::wvalue;
using crow::HTTPMethod::Get;

json error2json(const string &error) {
	json r;
	r["error"] = error;
	return r;
}

int main() {

	initialize_database();

	std::cout << "\n[Startup] Server started on \033 http://localhost:" << PORT << " \033";

	SimpleApp app;

	app.loglevel(LogLevel::Warning);

	CROW_ROUTE(app, "/hello").methods(Get)
	([]() {
		return "hello";
	});

	CROW_ROUTE(app, "/hello/json").methods(Get)
	([]() {
		json response;
		response["msg"] = "hello";
		return response;
	});

	CROW_ROUTE(app, "/add/<int>/<int>").methods(Get)
	([](const request &, const int a, const int b) {
		json response;
		response["result"] = a + b;
		return response;
	});

	CROW_ROUTE(app, "/hello/<string>").methods(Get)
	([](const request &, const string &name) {
		json response;
		response["result"] = name;
		return response;
	});

	app.port(PORT).run();
}
