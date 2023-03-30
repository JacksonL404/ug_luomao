#include <stdio.h>
#include <uf.h>
#include <uf_modl.h>

#define UF_CALL(X) (report( __FILE__, __LINE__, #X, (X)))

static int report(char *file, int line, char *call, int irc)
{
	if (irc)
	{
		char    messg[133];
		printf("%s, line %d:  %s\n", file, line, call);
		(UF_get_fail_message(irc, messg)) ?
			printf("    returned a %d\n", irc) :
			printf("    returned error %d:  %s\n", irc, messg);
	}
	return(irc);
}

static void do_ugopen_api(void)
{
	UF_FEATURE_SIGN create = UF_NULLSIGN;  // ����ʵ���ǣ���ʾ����ʵ��
	UF_FEATURE_SIGN sub = UF_NEGATIVE;  // ����ʵ���ǣ���ʾ��Ŀ��ʵ������ȥһ����
	UF_FEATURE_SIGN add = UF_POSITIVE;  //������
	UF_FEATURE_SIGN inter = UF_UNSIGNED; //������

	//����������
	double ip_orig[3] = { 0,0,0 }; //����Բ������
	double ip_diam = 30; //����ֱ��
	double ip_height = 16; //�����߶�
	double ip_direction[3] = { 0,0,1 }; //�������ɷ���
	int ip_number = 6; //��������
	tag_t ip_id; //����id
	uf6505(ip_orig, &ip_diam, &ip_height, &ip_number, ip_direction, &ip_id);

	//����Բ̨1��������
	double origin1[3] = { 0,0,0 };  //����Բ������
	char * height1 = "16";  //Բ̨�߶�
	char * diam1[2] = { "64.64","30" };  //���µ���ֱ��
	double direction1[3] = { 0,0,1 };  //���ɷ���
	tag_t cone_obj_id1;  //Բ̨id
	//���ú���UF_MODL_create_cone1����Բ̨��������id����cone_obj_id��
	UF_CALL(UF_MODL_create_cone1(inter, origin1, height1, diam1, direction1, &cone_obj_id1));

	//����Բ̨2��������
	double origin2[3] = { 0,0,0 }; 
	char * height2 = "16"; 
	char * diam2[2] = { "30", "64.64"};
	double direction2[3] = { 0,0,1 };
	tag_t cone_obj_id2;
	UF_CALL(UF_MODL_create_cone1(inter, origin2, height2, diam2, direction2, &cone_obj_id2));

	
	//����Բ����������
	double origin3[3] = { 0, 0, 0 };
	char * height3 = "16";
	char * diam3 = "20";
	double direction3[3] = { 0,0,1 };
	tag_t cyl_obj_id = NULL_TAG;
	UF_CALL(UF_MODL_create_cyl1(sub, origin1, height1, diam3, direction3, &cyl_obj_id));

	//�����飬������
	double corner_pt[3] = { -15,-1.75,10.5 };
	char *edge_len[3] = { "30","3.5","5.5" };
	tag_t blk_obj_id;
	UF_CALL(UF_MODL_create_block1(sub, corner_pt, edge_len, &blk_obj_id));

	//Բ������
	uf_list_p_t feat_list;
	tag_t feat_obj;
	double origin[3] = { 0.0, 0.0, 16.0 };
	double direction4[3] = { 0,0,1 };
	UF_CALL(UF_MODL_create_list(&feat_list));
	UF_CALL(UF_MODL_put_list_item(feat_list, blk_obj_id));
	UF_CALL(UF_MODL_create_circular_iset(0, origin, direction4, "3", "60",
		feat_list, &feat_obj));
	UF_CALL(UF_MODL_delete_list(&feat_list));

}

/*ARGSUSED*/
void ufusr(char *param, int *retcode, int paramLen)
{


	if (!UF_CALL(UF_initialize()))
	{
		do_ugopen_api();
		UF_CALL(UF_terminate());
	}
}

int ufusr_ask_unload(void)
{
	return (UF_UNLOAD_IMMEDIATELY);
}