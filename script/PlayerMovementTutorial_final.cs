using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using TMPro;
using System.IO.Ports;

public class PlayerMovementTutorial : MonoBehaviour
{
float rotationOnX;

  SerialPort stream = new SerialPort("/dev/cu.usbmodem1431",115200 );
float mouseSens = 50f;
public Transform player;
public moveplayer moving;
void Start()
{  
     stream.Open(); 
    Cursor.lockState =CursorLockMode.Locked;

}
void Update() 
{
    float m_X = 0;
     string  value = stream.ReadLine();
    string[] splitArray =  value.Split(char.Parse("/"));

if (splitArray.Length == 2)
{
    int value_rot = int.Parse(splitArray[1]);
     if (value_rot <1000 && value_rot > 0)
    {
        if (value_rot < 300)
             m_X = 1 * Time.deltaTime * mouseSens ;
        if (value_rot >= 300)
        {
            Debug.Log("hey" + value_rot);
              m_X = -1 * Time.deltaTime * mouseSens ;
        }
            player.Rotate(Vector3.up * m_X);

    }
    
}
    if  (splitArray.Length > 0)
    {
           int value_forward = int.Parse(splitArray[0]);

if (value_forward  <1000 && value_forward >= 0)
    moving.moveForward();

    }
 

   

   
} 





}