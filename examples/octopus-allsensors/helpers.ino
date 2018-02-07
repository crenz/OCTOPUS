void printMsg(const char * header, const String message) {    
    Serial.printf("[%s] ", header);
    for (int i = 0; i < 14-strlen(header); i++) {
        Serial.print(" ");
    }
    Serial.print(message);
}

void printlnMsg(const char * header, const String message) {    
    printMsg(header, message);
    Serial.println();
}
