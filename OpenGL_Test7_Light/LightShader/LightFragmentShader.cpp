#version 330 core
out vec4 FragColor;

uniform vec3 objectColor;
uniform vec3 lightColor;

in vec3 FragPos;        //片段的坐标位置
in vec3 Normal;         //片段的法向量
in vec3 LightPos;       //光源的坐标

void main()
{
    float ambientStrength = 0.1f;
    //环境光
    vec3 ambient = ambientStrength * lightColor;
    //漫反射光
    vec3 norm = normalize(Normal);  //标准化法向量
    vec3 lightDir = normalize(LightPos - FragPos); //标准化 光与片段位置向量差（光线方向）
    float diff = max(dot(norm, lightDir), 0.0); //向量点乘 得到cos余弦值
    vec3 diffuse = diff * lightColor;
    //镜面反射光
    vec3 viewDir = normalize(-FragPos);    //观察方向
    vec3 reflectDir = reflect(-lightDir, norm);     //反射光方向
    float specularStrength = 0.5;   //镜面强度
    float shiniess = 256;            //高光的反光度
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), shiniess);   //pow是次幂函数：x的y次方
    vec3 specular = specularStrength * spec * lightColor;
    //各种光的分量相加
    vec3 result = (ambient + diffuse + specular) * objectColor;
    FragColor = vec4(result, 1.0);
}
