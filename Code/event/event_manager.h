/*****************************************************************************************************************
* Copyright (c) 2015 Khalid Ali Al-Kooheji                                                                       *
*                                                                                                                *
* Permission is hereby granted, free of charge, to any person obtaining a copy of this software and              *
* associated documentation files (the "Software"), to deal in the Software without restriction, including        *
* without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell        *
* copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the       *
* following conditions:                                                                                          *
*                                                                                                                *
* The above copyright notice and this permission notice shall be included in all copies or substantial           *
* portions of the Software.                                                                                      *
*                                                                                                                *
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT          *
* LIMITED TO THE WARRANTIES OF MERCHANTABILITY, * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.          *
* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, * DAMAGES OR OTHER LIABILITY,      *
* WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE            *
* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                                                         *
*****************************************************************************************************************/
#pragma once



namespace ve {

class EventManager {
 public:
  EventManager() {}
  ~EventManager() {}
  template<typename Function>
  void AddEventListener(int event_id, const Function& listener) {
    auto& list = listener_map[event_id];
    //if (std::find(list.begin(),list.end(),listener)!= list.end()) {
      list.push_back(listener);
    //}
  }
  void TriggerEvent(int event_id, void* source, void* param = nullptr) {
    auto& list = listener_map[event_id];
    for(auto func : list) {
      func(source,param);
    }
  }
 private:
  typedef std::function<int (void*,void*)> EventListener;
  typedef std::vector<EventListener> EventListeners;
  std::map<int,EventListeners> listener_map;
};

}