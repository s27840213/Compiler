.class public compiler_hw3
.super java/lang/Object
.method public static test(II)I
.limit stack 50
.limit locals 50
	iload 0
	iload 1
	iadd
	ireturn
.end method
.method public static main([Ljava/lang/String;)V
.limit stack 50
.limit locals 50
	ldc 1
	istore 0
	ldc 5
	istore 1
	iload 0
	ldc 0
	i2f
	swap
	i2f
	swap
	fcmpl
	ifgt L_MT_TRUE_0
	iconst_0
	goto L_MT_FALSE_0
L_MT_TRUE_0:
	iconst_1
L_MT_FALSE_0:
	ifeq L_FALSE_ACTION_2
	ldc 10
	istore 0
	ldc "a>0"
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	goto IF_EXIT_0
L_FALSE_ACTION_2:
	iload 0
	ldc 0
	i2f
	swap
	i2f
	swap
	fcmpl
	iflt L_LT_TRUE_1
	iconst_0
	goto L_LT_FALSE_1
L_LT_TRUE_1:
	iconst_1
L_LT_FALSE_1:
	ifeq L_FALSE_ACTION_2
	ldc "a<0"
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	goto IF_EXIT_0
L_FALSE_ACTION_2:
	ldc "a=0"
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
IF_EXIT_0:
	ldc 5
	iload 0
	swap
	imul
	istore 0
	iload 0
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
	return
.end method
