#include "Queue.h"

#define _CRT_SECURE_NO_WARNINGS

#ifndef NULL
#define NULL 0
#endif
#ifndef printf
#include <stdio.h>
#endif
#ifndef calloc
#include <stdlib.h>
#endif
#ifndef strcpy
#include <string.h>
#endif

               Queue::Queue(int _editable) {
	this->first = NULL;
	this->editable_field = _editable;
}
               Queue::Queue(list_item_data _data, int _editable) {
	this->first = (list_item*)calloc(1, sizeof(list_item));
	if (this->first)
		this->first->data = _data;
	this->editable_field = _editable;
}
               Queue::Queue(const Queue& _copy, int _editable) {
	this->first = (list_item*)calloc(1, sizeof(list_item));
	if (this->first) {
		if (!_copy.first) {
			this->first = NULL;
			this->editable_field = _copy.editable_field;
			return;
		}
		this->first->data = _copy.first->data;
		list_item* last = this->first;
		list_item* last_copy = _copy.first;
		while (last_copy->next) {
			last_copy = last_copy->next;
			list_item* last_new = (list_item*)calloc(1, sizeof(list_item));
			if (last_new)
				last_new->data = last_copy->data;

			last->next = last_new;
			last = last_new;
		}
	}
	this->editable_field = _editable;
}
          void Queue::print_fields(const int _selected) {
	printf("\n  +----------------------------------------+----------------------------------------+\n");
	if (_selected & 1) {
		printf("  |                                  first | 0x%16p                     |\n  +----------------------------------------+----------------------------------------+\n", this->first);
	}
	if (_selected & 2) {
		printf("  |                               editable | %-32d       |\n  +----------------------------------------+----------------------------------------+\n", this->editable_field);
	}
}
          void Queue::set_editable_field(const int _editable) {
	this->editable_field = _editable;
}
list_item_data Queue::get_item(const bool _delete) {
	if (!(this->first)) return { /* protons_count: */ 0, /* name: */ "" };
	list_item_data res = this->first->data;
	if (_delete) {
		list_item* second = this->first->next;
		free(this->first);
		this->first = second;
	}
	return res;
}
          bool Queue::add_item(list_item_data _data) {
	if (!(this->first)) {
		this->first = (list_item*)calloc(1, sizeof(list_item));
		if (this->first) {
			this->first->data = _data;
			return true;
		} else return false;
	}
	list_item* last = this->first;
	while (last->next) last = last->next;
	last->next = (list_item*)calloc(1, sizeof(list_item));
	if (last->next) {
		last->next->data = _data;
		return true;
	} else return false;
}
		  bool Queue::add_item(int _protons_count, char _name[30]) {
	list_item_data _data;
	strcpy(_data.name, _name);
	_data.protons_count = _protons_count;
	return this->add_item(_data);
}
		  bool Queue::check_queue() {
			  if (!this->first) return false;
			  list_item* i = this->first;
			  while (i) {
				  if (i->next) {
					  list_item* j = i->next;
					  while (j) {
						  if (i->data.protons_count == j->data.protons_count) return true;
						  j = j->next;
					  }
				  }
				  i = i->next;
			  }
			  return false;
		  }
		  bool Queue::clear_items() {
	while (this->first) {
		list_item* second = this->first->next;
		free(this->first);
		this->first = second;
	}
	return true;
}
               Queue::~Queue() {
	while (this->first) {
		list_item* second = this->first->next;
		free(this->first);
		this->first = second;
	}
}
