#version 330 core
out vec4 FragColor;

uniform vec3 objectColor;
uniform vec3 lightColor;

in vec3 FragPos;        //片段的世界空间坐标位置
in vec3 Normal;         //片段的法向量
uniform vec3 lightPos;  //光源的世界空间坐标

void main()
{
    float ambientStrength = 0.1f;
    //环境光
    vec3 ambient = ambientStrength * lightColor;
    //漫反射光
    vec3 norm = normalize(Normal);  //标准化法向量
    vec3 lightDir = normalize(lightPos - FragPos); //标准化 光与片段位置向量差
    float diff = max(dot(norm, lightDir), 0.0); //向量点乘 得到cos余弦值
    vec3 diffuse = diff * lightColor;
    //各种光的分量相加
    vec3 result = (ambient + diffuse) * objectColor;
    FragColor = vec4(result, 1.0);
}
