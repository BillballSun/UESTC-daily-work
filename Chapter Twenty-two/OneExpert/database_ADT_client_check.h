#ifndef HEAD_database_ADT_client_check
#define HEAD_database_ADT_client_check
#define STD_vison 1
#if Max_event_amount<7||Max_event_amount>36
	#error Event_amount_flows
#elif Max_event_amount!=7
	#undef STD_vison
	#define STD_vison 0
#endif
#if Max_subject_name_length<16||Max_subject_name_length>255
	#error Subject name flows
#elif Max_subject_name_length!=64
	#undef STD_vison
	#define STD_vison 0
#endif
#if Expert_time!=10000ul
	#undef STD_vison
	#define STD_vison 0
	#if Expert_time<100
		#error It is too short to become an expert_time
	#elif Expert_time>1000000ul
		#error It is too long to accomplish in life time
	#endif
#endif
#endif
