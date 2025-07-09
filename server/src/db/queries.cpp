#include <cstdlib>
#include <filesystem>
#include <iostream>
#include "load_env.h"
#include <libpq-fe.h>
#include <crow/json.h>
#include <string>
#include <vector>

using namespace std;
using json = crow::json::wvalue;

string db_url;

void initialize_database() {
	const string env_path = std::filesystem::path(__FILE__).parent_path().parent_path().parent_path().string() + "/.env";
	load_env(env_path);

	const char* db   = getenv("PG_DB");
	const char* user = getenv("PG_USER");
	const char* host = getenv("PG_HOST");
	const char* port = getenv("PG_PORT");
	const char* pass = getenv("PG_PASSWORD");

	db_url = "host="    + string(host ? host : "") +
			 " port="    + string(port ? port : "") +
			 " dbname="  + string(db ? db : "") +
			 " user="    + string(user ? user : "") +
			 " password="+ string(pass ? pass : "");
	cout<<db_url;
}


// json db_query(const string& query, const vector<string>& params = {}) {
// 	PGconn* conn = PQconnectdb(db_url.c_str());
//
// 	if (PQstatus(conn) != CONNECTION_OK) {
// 		json err;
// 		err["error"] = PQerrorMessage(conn);
// 		PQfinish(conn);
// 		return err;
// 	}
//
// 	vector<const char*> paramValues;
// 	for (const std::string& p : params) {
// 		paramValues.push_back(p.c_str());
// 	}
//
// 	PGresult* res = PQexecParams(
// 		conn,
// 		query.c_str(),
// 		paramValues.size(),
// 		nullptr,
// 		paramValues.data(),
// 		nullptr,
// 		nullptr,
// 		0
// 	);
//
// 	if (!res) {
// 		json err;
// 		err["error"] = "Query execution returned null.";
// 		PQfinish(conn);
// 		return err;
// 	}
//
// 	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
// 		json err;
// 		err["error"] = PQresultErrorMessage(res);
// 		PQclear(res);
// 		PQfinish(conn);
// 		return err;
// 	}
//
// 	json result;
// 	int rows = PQntuples(res);
// 	int cols = PQnfields(res);
//
// 	for (int i = 0; i < rows; ++i) {
// 		json row;
// 		for (int j = 0; j < cols; ++j) {
// 			const char* val = PQgetvalue(res, i, j);
// 			const char* colName = PQfname(res, j);
// 			row[colName] = val ? val : "";
// 		}
// 		result[i] = std::move(row);
// 	}
//
// 	PQclear(res);
// 	PQfinish(conn);
// 	return result;
// }

