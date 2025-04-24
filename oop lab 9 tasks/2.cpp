#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Logger
{
private:
    vector<string> logs;
    int maxLogs;

    string formatMessage(const string &source, const string &messageType, const string &message)
    {
        return "[" + messageType + "] [" + source + "] " + message;
    }

public:
    Logger(int limit = 1000) : maxLogs(limit) {}

    void logInfo(const string &source, const string &message)
    {
        storeLog(formatMessage(source, "INFO", message));
    }

    void logWarning(const string &source, const string &message)
    {
        storeLog(formatMessage(source, "WARN", message));
    }

    void logError(const string &source, const string &message)
    {
        storeLog(formatMessage(source, "ERROR", message));
    }

    void storeLog(const string &logMessage)
    {
        if (logs.size() >= maxLogs)
        {
            logs.erase(logs.begin());
        }
        logs.push_back(logMessage);
    }

    vector<string> getLogs(const string &auditorKey) const
    {
        if (auditorKey != "secure-access")
            return {};
        return logs;
    }
};

int main()
{
    Logger logger;

    logger.logInfo("Network", "Connection established");
    logger.logWarning("Database", "Query took too long");
    logger.logError("Auth", "Invalid login attempt");
    logger.logInfo("System", "Scheduled task completed");

    vector<string> output = logger.getLogs("secure-access");
    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << endl;
    }

    return 0;
}
