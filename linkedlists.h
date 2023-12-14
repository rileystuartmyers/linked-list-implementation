#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#ifndef LINKING_LISTS_H
#define LINKING_LISTS_H

struct Node {

  Node *next;
  std::string data;
};
int size = 0;

struct Node *head;

void InsertAtPosition(std::string user_data, int position) {

  if ((position > size) || (position < 0)) {

    return;
  }

  Node *temp = new Node();
  temp->next = NULL;
  temp->data = user_data;

  if (position == 0) {

    temp->next = head;
    head = temp;
    ++size;

    return;
  }

  Node *index_temp = head;

  for (int i = 0; i < (position - 2); i++) {

    index_temp = index_temp->next;
  }

  temp->next = index_temp->next;
  index_temp->next = temp;
  size++;
}



std::string PrintAtPosition(int position) {

  /*if ((position >= size) || (position < 0)) {

    return;
  }*/

  Node *temp = head;
  int count = 0;

  while ((temp != NULL) && (count != position)) {

    temp = temp->next;
    count++;
  }

  return temp -> data;

}



void RemoveAtPosition(int position) {

  if ((position >= size) || (position < 0)) {

    return;
    
  }

  struct Node *temp = head;

  if (position == 0) {

    head = temp->next;
    free(temp);
    --size;

    return;
  }
  for (int i = 0; i < (position - 2); ++i) {

    temp = temp->next;
  }

  struct Node *temp2 = temp->next;
  temp->next = temp2->next;
  free(temp2);
  --size;
}

std::string CommandLines(std::string command_line) {

  std::string command;
  std::string index_string;
  std::string data;
  int index;


  std::istringstream str(command_line);
  str >> command;

  if (command == "Insert") {

    str >> index_string;
    str >> data;

    if (index_string == "Head") {

      index = 0;
      
    } else if (index_string == "Tail") {

      index = (size);
      
    } else {

      index = index_string[0] - '0';
      
    }

    InsertAtPosition(data, index);
    return "";
    
    
  } else if (command == "Print") {

    str >> index_string;
    std::string temp = "";

    for (int i = 0; i < index_string.length(); ++i) {

      if (!((index_string[i] == '[') || (index_string[i] == ']'))) {

        temp += index_string[i];
        
      }

    }

      if (temp == "Head") {

        index = 0;
        
      } else if (temp == "Tail") {

        index = (size);
        
      } else {

        index = temp[0] - '0';
        
      }

    return PrintAtPosition(index);
  
    
  } else if (command == "Remove") {

    str >> index_string;

    if (index_string == "Head") {

      index = 0;
      
    } else if (index_string == "Tail") {

      index = (size);
      
    } else {

      index = index_string[0] - '0';
      
    }

    RemoveAtPosition(index);
    return "";
    
  } else {

    return "";

  }
  
}

#endif
