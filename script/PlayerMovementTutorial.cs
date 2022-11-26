using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using TMPro;

public class PlayerMovementTutorial : MonoBehaviour
{
float rotationOnX;
float mouseSens = 200f;
public Transform player;

void Start()
{  
    Cursor.lockState =CursorLockMode.Locked;

}
void Update() 
{
    float m_X = Input.GetAxis("Mouse X") * Time.deltaTime * mouseSens *50;
    player.Rotate(Vector3.up * m_X);
} 





}