using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class moveplayer : MonoBehaviour
{
    public CharacterController controller;
    public float speed = 5f;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
       // float x = Input.GetAxis("Horizontal");
        
      

    }
    public void moveForward()
    {
       // float z = Input.GetAxis("Vertical");
 
          Vector3 move =  transform.forward * 1;
        controller.Move(move * speed * Time.deltaTime);
    }
}
