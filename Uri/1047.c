#include <stdio.h>

int main()
{
    int h_ini,m_ini,h_fim,m_fim;
    scanf("%d %d %d %d",&h_ini,&m_ini,&h_fim,&m_fim);
    int h_res, m_res;
    h_res = h_fim - h_ini;
    m_res = m_fim - m_ini;
    if(h_ini==h_fim && m_ini==m_fim)
    {
        h_res=24;
    }
    if(m_res<0){
        h_res--;
        m_res= 60 + (m_fim - m_ini);
    }
    printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n",h_res,m_res);
    return 0;
}