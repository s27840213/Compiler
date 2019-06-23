.class public compiler_hw3
.super java/lang/Object
.field public static g Ljava/lang/String; = "I am global la !"
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
	ldc 0
	istore 2
	ldc 1
	i2f
	fstore 3
	iload 0
	iload 1
	i2f
	swap
	i2f
	swap
	fcmpl
	iflt LABLE_LT_T_0
	iconst_0
	goto LABLE_LT_F_0
LABLE_LT_T_0:
	iconst_1
LABLE_LT_F_0:
	iload 2
	iload 1
	i2f
	swap
	i2f
	swap
	fcmpl
	ifgt LABLE_MT_T_1
	iconst_0
	goto LABLE_MT_F_1
LABLE_MT_T_1:
	iconst_1
LABLE_MT_F_1:
	ior
	ifeq LABLE_F_ACTION_2
	iload 0
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
L_WHILE_1_2:
	iload 0
	ldc 5
	i2f
	swap
	i2f
	swap
	fcmpl
	iflt LABLE_LT_T_2
	iconst_0
	goto LABLE_LT_F_2
LABLE_LT_T_2:
	iconst_1
LABLE_LT_F_2:
	ifeq WHILE_EXIT_0_3
	iload 0
	ldc 1
	iadd
	istore 0
	iload 0
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
	iload 0
	iload 2
	invokestatic compiler_hw3/test(II)I
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
	getstatic compiler_hw3/g Ljava/lang/String;
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	goto L_WHILE_1_2
WHILE_EXIT_0_3:
	goto IF_EXIT_0
LABLE_F_ACTION_2:
IF_EXIT_0:
	iload 0
	iload 1
	invokestatic compiler_hw3/test(II)I
	istore 0
	return
.end method
