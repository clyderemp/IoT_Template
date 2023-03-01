/** Generated by itemis CREATE code generator. */
/* Implements a standard statechart trace handler which adapts to the
 * YET tracing library.
 */


#include "SmartTemplate_tracer.h"
#include "SmartTemplate_meta.h"

#include <string.h>
#include <stdlib.h>


#ifndef SC_UNUSED
#define SC_UNUSED(P) (void)(P)
#endif

static sc_string default_scope_name = "SmartTemplate";

static yet_value_serializer feature_value_serializer[20];



static void init_feature_value_serializer() {
	feature_value_serializer[0] = yet_serialize_void;
	feature_value_serializer[1] = yet_serialize_void;
	feature_value_serializer[2] = yet_serialize_void;
	feature_value_serializer[3] = yet_serialize_void;
	feature_value_serializer[4] = yet_serialize_void;
	feature_value_serializer[5] = yet_serialize_void;
	feature_value_serializer[6] = yet_serialize_void;
	feature_value_serializer[7] = yet_serialize_string;
	feature_value_serializer[8] = yet_serialize_bool;
	feature_value_serializer[9] = yet_int_serializer_function(sizeof(sc_integer), true);
	feature_value_serializer[10] = yet_int_serializer_function(sizeof(sc_integer), true);
	feature_value_serializer[11] = yet_int_serializer_function(sizeof(sc_integer), true);
	feature_value_serializer[12] = yet_int_serializer_function(sizeof(sc_integer), true);
	feature_value_serializer[13] = yet_serialize_void;
	feature_value_serializer[14] = yet_serialize_void;
	feature_value_serializer[15] = yet_serialize_bool;
	feature_value_serializer[16] = yet_int_serializer_function(sizeof(sc_integer), true);
	feature_value_serializer[17] = yet_int_serializer_function(sizeof(sc_integer), true);
	feature_value_serializer[18] = yet_serialize_bool;
	feature_value_serializer[19] = yet_int_serializer_function(sizeof(sc_integer), true);
}

static char* featureName(sc_integer featureId)
{
	return SmartTemplate_meta_feature_names[featureId];
}

static char* featureValue(sc_integer featureId, const void* valuePtr, char* buf)
{
	return (feature_value_serializer[featureId])(valuePtr, buf);
}

static char* stateName(sc_integer stateId)
{
	return SmartTemplate_meta_state_names[stateId];
}

static yet_error dispatchMessage(yet_scope *scope, yet_message * msg, char *fqn);

void smartTemplate_init_sc_tracer(yet_sc_tracer *tracer, SmartTemplate* machine, sc_string name)
{
	if (tracer != sc_null) {
		yet_init_sc_tracer(tracer, machine, &dispatchMessage);

		tracer->scope.name = default_scope_name;
		if (name != sc_null) {
			tracer->scope.name = name;
		}
		tracer->traceinfoProvider.featureName = featureName;
		tracer->traceinfoProvider.featureValue = featureValue;
		tracer->traceinfoProvider.stateName = stateName;
		
		machine->trace_handler = &(tracer->traceEventHandler);
	}
	init_feature_value_serializer();
}


/* Implementation of yet_handler callback function. Handles incoming stimuli and call appropriate state machine function. */
static yet_error dispatchMessage(yet_scope *scope, yet_message * msg, char *fqn)
{
	yet_sc_tracer* tracer = scope->instance;
	char* member;
	member = fqn;
	
	
	if(strcmp(member, "system.on") == 0) {
		/* Skip one message; this should not be re-raised on host */
		/* TODO: this is not optimal check if we can get rid of it */
		tracer->skip_raised_in_event++; 
		smartTemplate_system_raise_on(tracer->machine);
		return 0;
	}
	if(strcmp(member, "system.off") == 0) {
		/* Skip one message; this should not be re-raised on host */
		/* TODO: this is not optimal check if we can get rid of it */
		tracer->skip_raised_in_event++; 
		smartTemplate_system_raise_off(tracer->machine);
		return 0;
	}
	if(strcmp(member, "message") == 0) {
		sc_string converted = msg->value;
		smartTemplate_set_message(tracer->machine, converted);
		return 0;
	}
	if(strcmp(member, "WiFi_connection") == 0) {
		sc_boolean converted = (msg->value[0] == 't');
		smartTemplate_set_wiFi_connection(tracer->machine, converted);
		return 0;
	}
	if(strcmp(member, "Temp_value") == 0) {
		sc_integer converted = (sc_integer)atol(msg->value);
		smartTemplate_set_temp_value(tracer->machine, converted);
		return 0;
	}
	if(strcmp(member, "Power_input") == 0) {
		sc_integer converted = (sc_integer)atol(msg->value);
		smartTemplate_set_power_input(tracer->machine, converted);
		return 0;
	}
	if(strcmp(member, "Power_total") == 0) {
		sc_integer converted = (sc_integer)atol(msg->value);
		smartTemplate_set_power_total(tracer->machine, converted);
		return 0;
	}
	if(strcmp(member, "Power_required") == 0) {
		sc_integer converted = (sc_integer)atol(msg->value);
		smartTemplate_set_power_required(tracer->machine, converted);
		return 0;
	}
	if(strcmp(member, "system.isOn") == 0) {
		sc_boolean converted = (msg->value[0] == 't');
		smartTemplate_system_set_isOn(tracer->machine, converted);
		return 0;
	}
	if(strcmp(member, "SensorInput.detection_time") == 0) {
		sc_integer converted = (sc_integer)atol(msg->value);
		smartTemplate_SensorInput_set_detection_time(tracer->machine, converted);
		return 0;
	}
	if(strcmp(member, "SensorInput.timeout_time") == 0) {
		sc_integer converted = (sc_integer)atol(msg->value);
		smartTemplate_SensorInput_set_timeout_time(tracer->machine, converted);
		return 0;
	}
	if(strcmp(member, "SensorOutput.activity") == 0) {
		sc_boolean converted = (msg->value[0] == 't');
		smartTemplate_SensorOutput_set_activity(tracer->machine, converted);
		return 0;
	}
	if(strcmp(member, "SensorOutput.counter") == 0) {
		sc_integer converted = (sc_integer)atol(msg->value);
		smartTemplate_SensorOutput_set_counter(tracer->machine, converted);
		return 0;
	}
	
	
	return YET_ERR_INVALID_KEY;
}
