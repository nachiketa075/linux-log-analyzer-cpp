#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>

using namespace std;

void analyzeFailedLoginAttempts()
{
    ifstream authenticationLog("auth.log");
    ofstream suspiciousReport("suspicious_ips.txt");

    if (!authenticationLog)
    {
        cout << "Unable to open log file" << endl;
        return;
    }

    unordered_map<string, int> failedLoginCount;
    string logEntry;
    int suspiciousIpCount = 0;

    while (getline(authenticationLog, logEntry))
    {
        if (logEntry.find("Failed") != string::npos)
        {
            size_t ipPosition = logEntry.find("from");

            if (ipPosition != string::npos)
            {
                string ipAddress = logEntry.substr(ipPosition + 5);

                failedLoginCount[ipAddress]++;
            }
        }
    }

    cout << "\nSuspicious Login Attempt Analysis\n";
    cout << "---------------------------------\n";

    for (auto loginRecord : failedLoginCount)
    {
        cout << "IP Address: " << loginRecord.first
             << " | Failed Attempts: " << loginRecord.second;

        if (loginRecord.second >= 3)
        {
            cout << "  --> Suspicious";
            suspiciousReport << loginRecord.first << endl;
            suspiciousIpCount++;
        }

        cout << endl;
    }

    cout << "\nTotal Suspicious IPs: " << suspiciousIpCount << endl;

    authenticationLog.close();
    suspiciousReport.close();
}

int main()
{
    analyzeFailedLoginAttempts();

    return 0;
}