{\rtf1\ansi\ansicpg1252\cocoartf1404\cocoasubrtf470
{\fonttbl\f0\fnil\fcharset0 Menlo-Bold;\f1\fnil\fcharset0 Menlo-Regular;}
{\colortbl;\red255\green255\blue255;\red127\green0\blue85;\red42\green0\blue255;\red0\green80\blue50;
\red0\green0\blue192;}
\paperw11900\paperh16840\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\deftab720
\pard\pardeftab720\partightenfactor0

\f0\b\fs24 \cf2 #include
\f1\b0 \cf3 <iostream>\cf0 \

\f0\b \cf2 #include
\f1\b0 \cf3 <stack>\cf0 \

\f0\b \cf2 #include
\f1\b0 \cf3 <queue>\cf0 \

\f0\b \cf2 using
\f1\b0 \cf0  
\f0\b \cf2 namespace
\f1\b0 \cf0  std;\

\f0\b \cf2 class
\f1\b0 \cf0  \cf4 sbc\cf0 \
\{\

\f0\b \cf2 public
\f1\b0 \cf0 :\
	
\f0\b \cf2 int
\f1\b0 \cf0  \cf5 a\cf0 [10][10],\cf5 mincost\cf0 =0,\cf5 n\cf0 ,\cf5 minindex\cf0 ,\cf5 count\cf0 =1;\
	
\f0\b \ul sbc
\f1\b0 ()\ulnone \
\ul 	\{\ulnone \
\ul 		cout<<\cf3 \ulc3 "\\n enter no of vertices::"\cf0 \ulc0 ;\ulnone \
\ul 		cin>>\cf5 \ulc5 n\cf0 \ulc0 ;\ulnone \
\ul 		
\f0\b \cf2 \ulc2 for
\f1\b0 \cf0 \ulc0 (
\f0\b \cf2 \ulc2 int
\f1\b0 \cf0 \ulc0  i=0;i<\cf5 \ulc5 n\cf0 \ulc0  ;i++)\ulnone \
\ul 		\{\ulnone \
\ul 			
\f0\b \cf2 \ulc2 for
\f1\b0 \cf0 \ulc0 (
\f0\b \cf2 \ulc2 int
\f1\b0 \cf0 \ulc0  j=0;j<\cf5 \ulc5 n\cf0 \ulc0 ;j++)\ulnone \
\ul 			\{\ulnone \
\ul 				\cf5 \ulc5 a\cf0 \ulc0 [i][j]=0;\ulnone \
\ul 			\}\ulnone \
\ul 		\}\ulnone \
\ul 	\}\ulnone \
\
	
\f0\b \cf2 void
\f1\b0 \cf0  
\f0\b acc
\f1\b0 ()\
	\{\
		
\f0\b \cf2 for
\f1\b0 \cf0 (
\f0\b \cf2 int
\f1\b0 \cf0  i=0;i<\cf5 n\cf0  ;i++)\
				\{\
					
\f0\b \cf2 for
\f1\b0 \cf0 (
\f0\b \cf2 int
\f1\b0 \cf0  j=i+1;j<\cf5 n\cf0 ;j++)\
					\{\
\
						cout<<\cf3 "\\n value between :"\cf0 <<i<<\cf3 "and::"\cf0 <<j;\
						cin>>\cf5 a\cf0 [i][j];\
			            \cf5 a\cf0 [j][i] = \cf5 a\cf0 [i][j];\
					\}\
				\}\
	\}\
\
	
\f0\b \cf2 void
\f1\b0 \cf0  
\f0\b disp
\f1\b0 ()\
	\{\
		
\f0\b \cf2 for
\f1\b0 \cf0 (
\f0\b \cf2 int
\f1\b0 \cf0  i=0;i<\cf5 n\cf0  ;i++)\
		\{\
			
\f0\b \cf2 for
\f1\b0 \cf0 (
\f0\b \cf2 int
\f1\b0 \cf0  j=0;j<\cf5 n\cf0 ;j++)\
			\{\
				cout<<\cf5 a\cf0 [i][j]<<\cf3 "\\t"\cf0 ;\
			\}\
			cout<<\cf3 "\\n"\cf0 ;\
		\}\
	\}\
\
	
\f0\b \cf2 void
\f1\b0 \cf0  
\f0\b prim
\f1\b0 ()\
	\{\
		
\f0\b \cf2 int
\f1\b0 \cf0  visit[10],cost=0,off[10],mincost;\
		
\f0\b \cf2 for
\f1\b0 \cf0 (
\f0\b \cf2 int
\f1\b0 \cf0  i=0;i<10;i++)\
		\{\
			visit[i]=0;\
			off[i]=i;\
		\}\
		visit[0]=1;\
		cout<<\cf3 "\\n shortest path::"\cf0 ;\
		cout<<\cf3 "\\n"\cf0 <<off[0]<<\cf3 "->"\cf0 ;\
		
\f0\b \cf2 while
\f1\b0 \cf0 (1)\
		\{\
			mincost=1000;\
		
\f0\b \cf2 for
\f1\b0 \cf0 (
\f0\b \cf2 int
\f1\b0 \cf0  i=0;i<\cf5 n\cf0 ;i++)\
				\{\
					
\f0\b \cf2 for
\f1\b0 \cf0 (
\f0\b \cf2 int
\f1\b0 \cf0  j=0;j<\cf5 n\cf0 ;j++)\
					\{\
						
\f0\b \cf2 if
\f1\b0 \cf0 (visit[i]==1 && \cf5 a\cf0 [i][j]!=0 && \cf5 a\cf0 [i][j]<mincost && visit[j]==0)\
						\{\
							\cf5 minindex\cf0 =j;\
							mincost=\cf5 a\cf0 [i][j];\
						\}\
					\}\
				\}\
		visit[\cf5 minindex\cf0 ]=1;\
		cout<<off[\cf5 minindex\cf0 ]<<\cf3 "->"\cf0 ;\
		cost=mincost+cost;\
		\cf5 count\cf0 ++;\
\
		
\f0\b \cf2 if
\f1\b0 \cf0 (\cf5 count\cf0 ==\cf5 n\cf0 )\
		\{\
			
\f0\b \cf2 break
\f1\b0 \cf0 ;\
		\}\
		\}\
		cout<<\cf3 "\\n \ul min\ulnone  cost::"\cf0 <<cost;\
	\}\
\};\

\f0\b \cf2 int
\f1\b0 \cf0  
\f0\b main
\f1\b0 ()\
\{\
	\cf4 sbc\cf0  s;\
	s.acc();\
	s.disp();\
	s.prim();\
	
\f0\b \cf2 return
\f1\b0 \cf0  0;\
\}\
}